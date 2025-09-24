#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 函数声明
static double binomial_coefficient(int n, int k);
static double bernstein_polynomial(double t, int i, int n);
static void build_control_points(double* middle_points, int m, double* control_points);
static double* calculate_bezier_curve(double* control_points, int num_points, int n);

double* create_bezier_curve(double* y_values, int n) {
    // 获取中间控制点个数m
    int m = 0;
    if(y_values != NULL) {
        // 计算数组元素个数
        // 注意：这在C语言中不安全，因为无法保证调用者传递了数组大小
        // 更安全的方式应该由调用者传递数组大小
        m = sizeof(y_values) / sizeof(y_values[0]);
    }
    
    // 分配控制点内存
    int num_control_points = m + 2;
    double* control_points = (double*)malloc(num_control_points * 2 * sizeof(double));
    if (!control_points) {
        printf("内存分配失败\n");
        return NULL;
    }
    
    // 构建贝塞尔控制点集合
    build_control_points(y_values, m, control_points);
    
    // 生成贝塞尔曲线
    double* curve_points = calculate_bezier_curve(control_points, num_control_points, n);
    
    // 释放控制点内存
    free(control_points);
    
    return curve_points;
}

double binomial_coefficient(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    k = (k > n - k) ? n - k : k;
    
    double result = 1.0;
    for (int i = 1; i <= k; i++) {
        result = result * (n - i + 1) / i;
    }
    return result;
}

double bernstein_polynomial(double t, int i, int n) {
    double bc = binomial_coefficient(n, i);
    double ti = pow(t, i);
    double tni = pow(1 - t, n - i);
    return bc * ti * tni;
}

void build_control_points(double* middle_points, int m, double* control_points) {
    // 添加起点
    control_points[0] = 0.0;
    control_points[1] = 0.0;
    
    // 添加中间控制点
    for (int i = 0; i < m; i++) {
        // 计算x坐标 - [0,1]区间均匀分布（不含0和1）
        double x = (double)(i + 1) / (m + 1);
        control_points[2 * (i + 1)] = x;
        control_points[2 * (i + 1) + 1] = middle_points[i];
    }
    
    // 添加终点
    control_points[2 * (m + 1)] = 1.0;
    control_points[2 * (m + 1) + 1] = 1.0;
}

double* calculate_bezier_curve(double* control_points, int num_points, int n) {
    // 确保n至少为2
    if (n < 2) n = 2;
    
    // 分配结果内存
    double* curve_points = (double*)malloc(n * sizeof(double));
    if (!curve_points) {
        printf("内存分配失败\n");
        return NULL;
    }
    
    // 计算每个采样点
    for (int pt = 0; pt < n; pt++) {
        double t = (double)pt / (n - 1);
        double y_sum = 0.0;
        
        // 计算所有控制点的权重
        for (int i = 0; i < num_points; i++) {
            double weight = bernstein_polynomial(t, i, num_points - 1);
            y_sum += control_points[2 * i + 1] * weight;
        }
        
        // 保存y坐标值
        curve_points[pt] = y_sum;
    }
    
    return curve_points;
}
