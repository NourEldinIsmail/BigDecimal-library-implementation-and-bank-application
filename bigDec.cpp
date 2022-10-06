#include "bigDec.h"
bool isSmaller(string str1, string str2)
{
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;

    return false;
}

BigDecimalInt::BigDecimalInt(string decStr){
    if(sign !='-'){
    if(decStr[0] == '-' || decStr[0] == '+'){
        sign = decStr[0];
        decStr.erase(0, 1);
        decimal = decStr;
    }
    else{
        decimal = decStr;
        sign = '+';
    }
}}

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
        cout<<decimal;
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
    if((sign == '+'&&anotherDec.getSign()=='+')||(sign == '-'&&anotherDec.getSign()=='-')){
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
            string tmp = anotherDec.getDec();
            for(int i=0;i<diff;i++){
                tmp = '0'+tmp;
            }
            anotherDec.set_dec(tmp);
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
        ans.set_sign(sign);
        ans.set_dec(result);
        return ans;

     }

}

BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec) {
    BigDecimalInt ans;
    string str = "";
if(isSmaller(decimal,anotherDec.getDec())){
    string tmp = anotherDec.getDec();
    swap(decimal,tmp);
    anotherDec.set_dec(tmp);
    ans.set_sign('-');}
if(decimal.size()>anotherDec.getDec().size()){
    int diff = decimal.size()-anotherDec.getDec().size();
    string tmp = anotherDec.getDec();
    for(int i=0;i<diff;i++){
        tmp = '0'+tmp;
    }
    anotherDec.set_dec(tmp);
}
string tmp = anotherDec.getDec();
int carry=0;
for(int i=tmp.size();i>=0;i--){
    int sum = (int)decimal[i]-(int)tmp[i]-carry;
    if(sum>=0){
        carry = 0;
        str += to_string(sum);
    }
    else{
        carry =1;
        sum+=10;
        str+= to_string(sum);
    }
}
    reverse(str.begin(),str.end());
str.pop_back();
ans.set_dec(str);
return ans;



}

