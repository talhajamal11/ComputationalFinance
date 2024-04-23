#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include "data/csv.h"


using namespace std;


class Point{
    public:
        double mean;
        double std_div;

    Point(double mean, double std_div){
        this->mean = mean;
        this->std_div = std_div;
    }
};


// In this tutorial we will be looking at the stastical properties of a portfolio on the data you have received for the coursework. 
// Just like in the tutorial the first part will be loading the data. Then, you will fill in a Portfolio class and complete the outlined methods. 

// Once you are done, copy the printed data into the provided jupyter notebook to visulize the statistics. In the main method you can set your 
// own portfolio weights and see how it performs. 

class Portfolio{
    private:
        vector<double> weights;

    public:
        int num_weights;

    Portfolio(vector<double> weights, int num_weights){
        // NOTICE WE USE this-> because the input has the same name as the attirbutes. "this" is the point to the class object. 
        this->weights = weights;
        this->num_weights = num_weights;
    }   

    // Compute the total mean of the portfolio interval returns. 
    double total_means(double** data, int duration){
        double mean_curr = 0.0;

        // Begin YOUR CODE


        // End YOUR CODE

        return mean_curr/duration;
    }

    // Compute the total variance of the portfolio interval returns. 
    double total_variance(double** data, int duration, double mean){
        double var_curr = 0.0;
        double curr_return = 0.0;

        // Begin YOUR CODE


        // End YOUR CODE

        return var_curr/duration;
    }

    // Compute an monte carloe estimate of the mean and standard deviation of the portfolio interval returns with the given number of trials.
    Point* simple_mc(double** data, int duration, int num_trials){
        
        int rand_t = 0; // Use "rand() % duration" to get a random return interval. To get a different sequence of random numbers set a seed with srand.

        // Begin YOUR CODE


        // End YOUR CODE

        double sample_mean = 0;
        double sample_var = 0;

        // Begin YOUR CODE


        // End YOUR CODE

        Point* mc_point = new Point(sample_mean, pow(sample_var, 0.5));

        return mc_point;
    }

};


double string_to_double( const std::string& s );
void readData(double **data,string fileName);



int  main (int  argc, char  *argv[])
{
    int numberAssets=83; // Small: 5
    int numberReturns=700; // Small 10
	double **returnMatrix=new double*[numberAssets]; // a matrix to store the return data
    //allocate memory for return data
    for(int i=0;i<numberAssets;i++){returnMatrix[i]=new double[numberReturns];}
		
    //read the data from the file and store it into the return matrix
    string fileName="data/asset_returns.csv"; // "data/asset_returns_small.csv"
	readData(returnMatrix, fileName);
    
    vector<double> weights(numberAssets, 1./numberAssets); // SET THIS TO TRY DIFFERENT PORTFOLIO STRATEGIES 
    Portfolio* pf = new Portfolio(weights, numberAssets);

    double true_mean = pf->total_means(returnMatrix, numberReturns);
    double true_std = pow(pf->total_variance(returnMatrix, numberReturns, true_mean), 0.5);

    int num_mc_estimates = 100; // SET THIS TO TRY DIFFERENT VALUES 
    vector<Point*> mc_estimates(num_mc_estimates, nullptr);
    int num_mc_trials = 100; // SET THIS TO TRY DIFFERENT VALUES 

    for(int t=0; t<num_mc_estimates; t++){mc_estimates[t] = pf->simple_mc(returnMatrix, numberReturns, num_mc_trials);}

    cout << "True Mean: " << true_mean << endl;
    cout << "True Std: " << true_std << endl;
    cout << "MC Data: " << endl;
    cout << "[";
    for(int t=0; t<num_mc_estimates; t++){
        cout << "[" + to_string(mc_estimates[t]->mean) + ", " + to_string(mc_estimates[t]->std_div);

        if(t == num_mc_estimates - 1){
            cout << "]";
        }else{
            cout << "], "; 
        }
    }
    cout << "]" << endl;


	return 0;
}


double string_to_double( const std::string& s )
{
	std::istringstream i(s);
	double x;
	if (!(i >> x))
		return 0;
	return x;
} 

void readData(double **data,string fileName)
{
	char tmp[30];
	ifstream file (strcpy(tmp, fileName.c_str()));
	Csv csv(file);
	string line;
	if (file.is_open())
	{
		int i=0;
		while (csv.getline(line) != 0) {
         	for (int j = 0; j < csv.getnfield(); j++)
            {
               double temp=string_to_double(csv.getfield(j));
               data[j][i]=temp;
            }
            i++;
		}
		
		file.close();
	}
	else {cout <<fileName <<" missing\n";exit(0);}
}