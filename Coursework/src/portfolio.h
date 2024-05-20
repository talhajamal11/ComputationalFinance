//
// Created by Talha Jamal on 20/05/2024.
//

#ifndef COURSEWORK_PORTFOLIO_H
#define COURSEWORK_PORTFOLIO_H

#include <iostream>

class Portfolio {
public:
    Portfolio(const std::vector< std::vector<double> >& returns, double targetReturn);

    std::vector<double> calculateMeanReturn();
    std::vector< std::vector<double> > calculateCovarianceMatrix();
    std::vector<double> solveOptimization();

private:
    std::vector< std::vector<double> > returns;
    double targetReturn;

    std::vector<double> meanReturns;
    std::vector< std::vector<double> > covarianceMatrix;
    std::vector<double> conjugateGradient(const std::vector<std::vector<double>> &Q, const std::vector<double> &b,
                                          const std::vector<double> &x0);
};


#endif //COURSEWORK_PORTFOLIO_H
