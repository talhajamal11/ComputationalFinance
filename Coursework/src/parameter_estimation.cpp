//
// Created by Talha Jamal on 20/05/2024.
//

#include "parameter_estimation.h"
#include <numeric>
#include <vector>
#include <cmath>

std::vector<double> calculateMean(double** data, int numberAssets, int n)
{
    std::vector<double> mean(numberAssets, 0.0);
    for (int i = 0; i < numberAssets; i++)
    {
        double sum = std::accumulate(data[i], data[i] + n, 0.0);
        mean[i] = sum / n;
    }
    return mean;
}

std::vector< std::vector<double> >calculateCovarianceMatrix(double** data, int numberAssets, int n)
{
    std::vector< std::vector<double> > covariance(numberAssets, std::vector<double>(numberAssets, 0.0));
    std::vector<double> mean = calculateMean(data, numberAssets, n);
    for (int i = 0; i < numberAssets; ++i)
    {
        for (int j = 0; j < numberAssets; ++j)
        {
            double sum = 0.0;
            for (int k = 0; k < n; ++k)
            {
                sum += (data[i][k] - mean[i]) * (data[j][k] - mean[j]);
            }
            covariance[i][j] = sum / (n - 1);
        }
    }
    return covariance;
}