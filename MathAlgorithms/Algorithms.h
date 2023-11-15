#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include <cmath>
#include <ctype.h>

using namespace std;

// Resources for Euclides Algorithm --------------------------------------------------------------------------------------------------------------------------------------------

struct Equation_Lines // Used for normal Euclides
{
    int a;
    int b;
    int multiplier;
    int rest;
    int size;
    Equation_Lines();

};

struct Equation_Lines_Extended  // Used for extended Euclides
{
    int multiplier_one;
    int multiplier_two;
    int a;
    int b;
    Equation_Lines_Extended();
};

    Equation_Lines* Find_Largest_Common_Denominator();
    Equation_Lines* Reversed_Euclides_Algorithm(Equation_Lines* pointer);
    void Solve_Equation(Equation_Lines* pointer);

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Resources for Base Changes costs --------------------------------------------------------------------------------------------------------------------------------------

    struct ChangeBase {

        int nOldBase;
        int nNewBase;
        int nRest;
        int nQuota;

        ChangeBase();
};

    struct findinverse {
        int x = 0;
        int y = 0;
        int rest = 0;
        int Quota = 0;
        int One = 0;
        int Two = 0;
        int result = 0;
        char sign{};
    };


    void ChangeBase1();
    void eulersPhiFunction();
    void lcd();
    void findinversecalculator();
    int lcd(int nFirst, int nSecond);

    void tryequation();

#endif // ALGORITHMS_H
