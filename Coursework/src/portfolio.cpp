//
// Created by Talha Jamal on 20/05/2024.
//

#include "portfolio.h"
#include <cmath>
#include <numeric>
#include <iostream>

// Constructor for Portfolio Class
Portfolio::Portfolio(const std::vector<std::vector<double>> &returns, double targetReturn)
    : returns(returns), targetReturn(targetReturn){}

// Calculate Mean Returns
std::vector<double> Portfolio::calculateMeanReturn()
{
    size_t numAssets = returns.size();
    size_t numPeriods = returns[0].size();
    meanReturns.resize(numAssets);

    for (int i = 0; i < numAssets; ++i)
    {
        meanReturns[i] = std::accumulate(returns[i].begin(), returns[i].end(), 0.0) / numPeriods;
    }
    return meanReturns;
}

// Calculate Covariance Matrix
std::vector< std::vector<double> > Portfolio::calculateCovarianceMatrix() {
    size_t numAssets = returns.size();
    size_t numPeriods = returns[0].size();
    covarianceMatrix.resize(numAssets, std::vector<double>(numAssets, 0.0));

    // Calculate Mean Returns if they have not been calculated
    if (meanReturns.empty()) {
        calculateMeanReturn();
    }

    for (size_t i = 0; i < numAssets; ++i) {
        for (size_t j = 0; j < numAssets; ++j) {
            double cov = 0.0;
            for (size_t k = 0; k < numPeriods; ++k) {
                cov += (returns[i][k] - meanReturns[i]) * (returns[j][k] - meanReturns[j]);
            }
            covarianceMatrix[i][j] = cov / (numPeriods - 1);
        }
    }
    return covarianceMatrix;
}

// solve Optimization Problem by creating the System of Linear Equations needed
// for Conjugate Gradient Method
std::vector<double> Portfolio::solveOptimization()
{
    size_t n = meanReturns.size(); // number of Assets
    std::vector< std::vector<double> > Q()
}