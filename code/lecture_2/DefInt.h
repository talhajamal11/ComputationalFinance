//
// Created by Talha Jamal on 23/04/2024.
//

#ifndef LECTURE_2_DEFINT_H
#define LECTURE_2_DEFINT_H


class DefInt {
    private:
        double a, b; // integration limits
        double(*f)(double); // pointer to function f
    public:
        //DefInt(double a_, double b_, double(*f_)(double)): a(a_), b(b_), f(f_){};
        DefInt(double a_, double b_, double (*f_)(double));
        double ByTrapezoid(int N);
        double BySimpson(int N);
};

#endif //LECTURE_2_DEFINT_H
