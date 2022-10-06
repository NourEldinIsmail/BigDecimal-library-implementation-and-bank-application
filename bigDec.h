#ifndef BGDC
#define BGDC

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class BigDecimalInt{
    private: 
        string decimal;
        char sign;
    public:
        BigDecimalInt(string decStr);
        BigDecimalInt(int decInt);
};

#endif // bigDec.h