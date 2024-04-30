//
// Created by Talha Jamal on 23/04/2024.
//

#include "DefInt.h"
#include <iostream>
#include <cmath>

using namespace std;

double DefInt::DefInt(double a_, double b_, double (*f_)(double)): a(a_), b(b_),f(f_){}
