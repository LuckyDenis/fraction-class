// author = "D. Belavin"

#pragma once

#include <iostream>
#include <math.h>

class fraction{
    public:
        fraction();
        fraction(int & n, int & d);
        ~fraction();
        friend std::istream& operator >> (std::istream & stream, fraction & f);
        friend std::ostream& operator << (std::ostream & stream,  const fraction & f);
        friend fraction operator + (const fraction & f1, const fraction & f2);
        friend fraction operator - (const fraction & f1, const fraction & f2);
        friend fraction operator * (const fraction & f1, const fraction & f2);
        friend fraction operator / (const fraction & f1, const fraction & f2);
        friend const bool operator < (const fraction & f1, const fraction & f2);
        friend const bool operator > (const fraction & f1, const fraction & f2);
        friend const bool operator <= (const fraction & f1, const fraction & f2);
        friend const bool operator >= (const fraction & f1, const fraction & f2);
        friend const bool operator == (const fraction & f1, const fraction & f2);
        friend const bool operator != (const fraction & f1, const fraction & f2);
        void operator = (const fraction & f1);
    private:
        int numerator = 1;
        int denominator = 1;
};
