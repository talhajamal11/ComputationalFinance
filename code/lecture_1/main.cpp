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
    if (S0 <= 0.0 || R <= -1.0 || D <= -1.0 || U <= D){
        cout << "Illegal values for inputs" << endl;
        cout << "Terminating Program" << endl;
        return 1;
    }

    cout << "Data is legal" << endl;

    return 0;
}
