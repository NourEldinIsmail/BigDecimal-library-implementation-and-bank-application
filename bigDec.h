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
    bool operator< (BigDecimalInt anotherDec);
    bool operator> (BigDecimalInt anotherDec);
    bool operator==(BigDecimalInt anotherDec);
    int size();
    string getDec();
    char getSign();
    string getFull();
};
bool isSmaller(string str1, string str2);

bool equalsZero(string str);

ostream& operator<< (ostream& out, BigDecimalInt bigDec);

istream& operator>> (istream& in, BigDecimalInt& bigDec);

#endif // bigDec.h