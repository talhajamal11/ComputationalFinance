/*
Created by Talha Jamal on 16/04/2024.

Write a function called interchange that interchanges the contents
of two variables of type double which are to be passed to the function by reference.

*/

#include <iostream>

using namespace std;

void interchange(double& a, double& b){
    double temp = a;
    a = b;
    b = temp;
}

int main(){

    double obj1, obj2;
    cout << "Please input Object 1" << endl; cin>> obj1;
    cout << "Please input Object 2" << endl; cin>> obj2;
    cout << "Values before interchanging: \n" << "Object 1: " << obj1 << " Object 2: " << obj2 << endl;
    cout << "Interchange values" << endl;
    interchange(obj1, obj2);
    cout << "Values after interchanging: \n" << "Object 1: " << obj1 << " Object 2:" << obj2 << endl;
    return 0;
}
