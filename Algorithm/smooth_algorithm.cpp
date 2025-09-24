#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "smooth_algorithm.h"


// 平滑处理突变点
double* smooth_curve(double* a, double* b, int length, int window_size, double threshold, double sigma) {
    if (!a || !b || length <= 0 || window_size <= 0 || sigma <= 0) {
        printf("无效的输入参数\n");
        return NULL;
    }

    // 分配结果内存
    double* result = (double*)malloc(length * sizeof(double));
    if (!result) {
        printf("内存分配失败\n");
        return NULL;
    }

    // 初始化结果数组
    for (int i = 0; i < length; i++) {
        result[i] = a[i];
    }

    // 查找突变点索引
    int* abrupt_indices = (int*)malloc(length * sizeof(int));
    if (!abrupt_indices) {
        printf("内存分配失败\n");
        free(result);
        return NULL;
    }

    int abrupt_count = 0;
    for (int i = 0; i < length; i++) {
        if (fabs(b[i] - a[i]) > threshold) {
            abrupt_indices[abrupt_count++] = i;
        }
    }

    // 如果没有找到突变点，直接返回
    if (abrupt_count == 0) {
        free(abrupt_indices);
        return result;
    }

    // 对每个突变点进行平滑处理
    for (int idx = 0; idx < abrupt_count; idx++) {
        int i = abrupt_indices[idx];
        
        // 分配权重和差值数组内存
        double* weights = (double*)calloc(length, sizeof(double));
        double* diffs = (double*)calloc(length, sizeof(double));
        
        if (!weights || !diffs) {
            printf("内存分配失败\n");
            if (weights) free(weights);
            if (diffs) free(diffs);
            free(abrupt_indices);
            free(result);
            return NULL;
        }

        // 计算高斯权重和差值
        int start = (i - window_size) > 0 ? (i - window_size) : 0;
        int end = (i + window_size) < length ? (i + window_size) : length - 1;
        double diff = b[i] - a[i];
        
        for (int j = start; j <= end; j++) {
            int dist = j - i;
            double gaussian_weight = exp(-(double)(dist * dist) / (2.0 * sigma * sigma));
            
            if (gaussian_weight > weights[j]) {
                weights[j] = gaussian_weight;
            }
            
            diffs[j] += weights[j] * diff;
        }

        // 应用差值到结果数组
        for (int k = 0; k < length; k++) {
            result[k] += diffs[k];
        }

        // 释放临时内存
        free(weights);
        free(diffs);
    }

    // 释放临时内存
    free(abrupt_indices);
    
    return result;
}