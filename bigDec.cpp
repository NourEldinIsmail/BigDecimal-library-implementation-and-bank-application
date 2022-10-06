#include "bigDec.h"

BigDecimalInt::BigDecimalInt(string decStr){
    if(decStr[0] == '-' || decStr[0] == '+'){
        sign = decStr[0];
        decStr.erase(0, 1);
        decimal = decStr;
    }
    else{
        decimal = decStr;
        sign = '+';
    }
}

BigDecimalInt::BigDecimalInt(int decInt){
    if(decInt > 0){
        decimal = to_string(decInt);
        sign = '+';
    }
    else{
        string tmp = to_string(decInt);
        sign = tmp[0];
        tmp.erase(0,1);
        decimal = tmp;
    }
}

string BigDecimalInt::getDec(){
    return decimal;
}

char BigDecimalInt::getSign(){
    return sign;
}

string BigDecimalInt::getFull(){
    string tmp = "";
    if(sign == '-'){
        tmp.push_back(sign);
    }
    return tmp + decimal;
}