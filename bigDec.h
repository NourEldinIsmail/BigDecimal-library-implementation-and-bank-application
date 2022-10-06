#ifndef BGDC
#define BGDC

#include <iostream>
#include <string>
#include <cctype>
#include<algorithm>
#include<math.h>

using namespace std;

class BigDecimalInt{
    private: 
        string decimal;
        char sign;
    public:
    BigDecimalInt(){};
    BigDecimalInt(string decStr);
    BigDecimalInt(int decInt);
    void set_dec(string deci);
    void set_sign(char s);
    BigDecimalInt operator+ (BigDecimalInt anotherDec);
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    string getDec();
    char getSign();
    string getFull();
};

#endif // bigDec.h