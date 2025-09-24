#ifndef BEZIER_CURVE_WRAPPER_H
#define BEZIER_CURVE_WRAPPER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * 创建贝塞尔曲线
 * 
 * @param y_values 中间控制点的y坐标数组（[0,1]归一化值，默认x为均匀采样）
 * @param n 所需返回的曲精度数量（如4096）
 * @return 计算得到的贝塞尔曲线采样点数组，使用完后需要调用free()释放内存（[0,1]归一化值）
 */
double* create_bezier_curve(double* y_values, int n);

#endif // BEZIER_CURVE_WRAPPER_H