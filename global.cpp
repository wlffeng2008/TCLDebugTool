
#include "global.h"

bool isKeyPressed(int virtualKey)
{
    return (::GetAsyncKeyState(virtualKey) & 0x8000) != 0;
}


QVector<double> movingAverage(const QVector<double>& data, int windowSize)
{
    QVector<double> smoothed;
    for (int i = 0; i <= data.size() - windowSize; ++i)
    {
        double sum = 0;
        for (int j = 0; j < windowSize; ++j)
            sum += data[i + j];
        smoothed.append(sum / windowSize);
    }
    return smoothed;
}
