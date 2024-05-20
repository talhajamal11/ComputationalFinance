//
// Created by Talha Jamal on 19/05/2024.
//
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include "csv.h"
#include "read_data.h"
#include "parameter_estimation.h"

int  main (int  argc, char  *argv[])
{
    int numberAssets = 83; // Initialize Number of Assets
    int numberReturns = 700; // Max Length of Returns Data
    double **returnMatrix = new double*[numberAssets]; // a matrix to store the return data

    //allocate memory for return data
    for(int i=0;i<numberAssets;i++)
        returnMatrix[i]=new double[numberReturns];

    cout << "Reading Data" << std::endl;

    //read the data from the file and store it into the return matrix
    std::string fileName = "asset_returns.csv";
    checkFileInCurrentDirectory(fileName); // Check if File Exists and File Path is correct
    readData(returnMatrix,fileName); // Read return data from the file and store in 2D returnMatrix

    // Calculate Covariance Matrix
    int inSampleSize = 700;
    std::vector< std::vector<double> > covarianceMatrix = calculateCovarianceMatrix(returnMatrix, 3, inSampleSize);
    std::cout << "CovarianceMatrix" << std::endl;
    for (const auto& row: covarianceMatrix)
    {
        for(const auto& value: row)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    // Delete Memory
    for(int i=0;i<numberAssets;i++)
        delete[] returnMatrix[i];
    delete[] returnMatrix;
    cout << "Deleted Memory" << std::endl;
    return 0;
}
