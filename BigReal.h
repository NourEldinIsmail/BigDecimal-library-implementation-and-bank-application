#ifndef BIGDECIMAL_BIGREAL_H
#define BIGDECIMAL_BIGREAL_H
#include "bigDec.h"
#include <iostream>
#include <string>
using namespace std;


class BigReal {
public:
    BigReal();
    virtual ~BigReal();
    BigReal (double realNumber = 0.0); // Default constructor
    BigReal (string realNum);
    BigReal (BigDecimalInt bigInteger);
    BigReal (const BigReal& other); // Copy constructor
    BigReal (BigReal&& other); // Move constructor
    BigReal& operator= (BigReal& other); // Assignment operator
    BigReal& operator= (BigReal&& other); // Move assignment
    BigReal operator+ (BigReal& other);
    BigReal operator- (BigReal& other);
    bool operator< (BigReal anotherReal);
    bool operator> (BigReal anotherReal);
    bool operator== (BigReal anotherReal);
    int size();
    int sign();
    string* get_real();
    friend ostream& operator << (ostream& out, BigReal num);
    friend istream& operator >> (istream& out, BigReal num);

protected:
    string* real = new string ;
};


#endif //BIGDECIMAL_BIGREAL_H
