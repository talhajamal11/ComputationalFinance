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

    // Print the current working directory
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        std::cout << "Current working dir: " << cwd << std::endl;
    } else {
        perror("getcwd() error");
        return 1;
    }

    int numberAssets = 83; // Initialize Number of Assets
    int numberReturns = 700; // Max Length of Returns Data
    double **returnMatrix = new double*[numberAssets]; // a matrix to store the return data

    //allocate memory for return data
    for(int i=0;i<numberAssets;i++)
        returnMatrix[i]=new double[numberReturns];

    cout << "Reading Data" << std::endl;

    // Construct the full path to the file
    std::string fileName = "asset_returns.csv";
    std::string fullPath = std::string(cwd) + "/" + fileName;

    // Check if the file exists
    std::ifstream file(fullPath);
    if (!file)
    {
        std::cerr << "File " << fullPath << " does not exist." << std::endl;
        return 1;
    }
    else
    {
        std::cout << "File " << fullPath << " exists" << std::endl;
    }
    file.close();

    //read the data from the file and store it into the return matrix
    //string fileName="Coursework/src/asset_returns_small.csv";
    readData(returnMatrix,fileName);

    // Calculate and Print Average of First 10 Assets
    int inSampleSize = 700;
    std::vector<double> meanReturns = calculateMean(returnMatrix, 10, inSampleSize);
    std::cout << "Mean Returns: " << std::endl;
    for (double mean: meanReturns)
    {
        std::cout << mean << " ,";
    }
    std::cout << std::endl;

    // Delete Memory
    for(int i=0;i<numberAssets;i++)
        delete[] returnMatrix[i];
    delete[] returnMatrix;
    cout << "Deleted Memory" << std::endl;
    return 0;
}
