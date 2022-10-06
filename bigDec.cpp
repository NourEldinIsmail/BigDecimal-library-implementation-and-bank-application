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
void BigDecimalInt::set_dec(string deci) {decimal=deci;}

void BigDecimalInt::set_sign(char s) {sign = s;}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec) {
    BigDecimalInt ans;
    if(sign == '+'&&anotherDec.getSign()=='+'){
        string result = "";
        int sum, carry=0;
        if(decimal.size()<anotherDec.getDec().size()){
            int diff = anotherDec.getDec().size()-decimal.size();
            for(int i=0;i<diff;i++){
                decimal='0'+decimal;
            }
        }
        else if(anotherDec.getDec().size()<decimal.size()){
            int diff = decimal.size() - anotherDec.getDec().size();
            for(int i=0;i<diff;i++){
                anotherDec.getDec() = '0' + anotherDec.getDec();
            }
        }
        for(int i=decimal.length()-1; i>=0; i--){
            sum = (int)decimal[i]-'0' + (int)anotherDec.getDec()[i]-'0' + carry;
            if(sum > 9){
                result = to_string(sum%10) + result;
                carry = sum/10;
            }else{
                result = to_string(sum) + result;
                carry = 0;
            }
        }

        if(carry != 0){
            result = to_string(carry) + result;
        }
        ans.set_dec(result);
        return result;
     }

}