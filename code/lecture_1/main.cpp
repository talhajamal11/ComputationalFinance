#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Store Variables
    double S0, U, D, R;

    // Enter Inputs
    cout << "Enter Stock Price" << endl; cin >> S0;
    cout << "Enter Up Factor" << endl; cin >> U;
    cout << "Enter Down Factor" << endl; cin >> D;
    cout << "Enter Risk Free Rate" << endl; cin >> R;

    // Check legality of inputs - exit if illegal values entered
    if (S0 <= 0.0 || R <= -1.0 || D <= -1.0 || U <= D) {
        cout << "Illegal values for inputs" << endl;
        cout << "Terminating Program" << endl;
        return 1;
    }

    // Check for Arbitrage
    if (R >= U || R <= D){
        cout << "Arb exists - terminating program" << endl;
        return 1;
    }

    // Calculate Risk Neutral Probability
    double q = (R - D)/(U - D);
    if (q <= 0.0 || q >= 1.0){
        cout << "Risk Neutral Probability incorrect - Arbitrage Exists - Terminating Program" << endl;
        return 1;
    }

    cout << "Data is legal" << endl;
    cout << "Risk Neutral Probability " << q << endl;

    // Calculate Stock Price at a certain node

    // Request user for Node and i
    int n, i;
    cout << "Please enter n: " << endl; cin >> n;
    cout << "Please enter i: " << endl; cin >> i;

    double StockPrice = S0*pow(1 + U, i)*pow(1 + D, n-i);
    cout << "Stock Price is: " << StockPrice << endl;

    return 0;
}
