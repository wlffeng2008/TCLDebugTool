#ifndef SMOOTH_ALGORITHM_H
#define SMOOTH_ALGORITHM_H

#include <stdlib.h>
#include <math.h>

/**
 * 平滑处理突变点
 * 
 * @param a 变化前的参考平滑曲线（归一化值）
 * @param b 变化后含突兀点（即人工手动调整的点）的需要平滑的曲线（归一化值，长度与a相同）
 * @param length 曲线点数（如4096）
 * @param window_size 窗口大小（高斯平滑窗口大小，推荐取至少1/4的曲线长度，即1024）
 * @param threshold 阈值（判定为突兀点的阈值，对归一化曲线值建议取1/4096）
 * @param sigma 高斯权重标准差（默认50,其他值的平滑程度不同，可以尝试）
 * @return 平滑后的曲线（归一化值，长度与a和b相同）
 */
double* smooth_curve(double* a, double* b, int length, int window_size, double threshold, double sigma);

#endif // SMOOTH_ALGORITHM_H
