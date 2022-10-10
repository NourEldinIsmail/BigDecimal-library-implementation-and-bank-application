#include "bigDec.h"
bool isSmaller(string str1, string str2)
{
    for (int i = 0; i < str1.size(); i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;

    return false;
}

bool equalsZero(string str){
    for(int i = 0; i < str.size(); i++){
        if(str[i] != '0'){
            return false;
        }
    }
    return true;
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
    }
    if(equalsZero(decimal)){
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
        cout<<decimal;
    }
    if(equalsZero(decimal)){
        sign = '+';
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
    long long k = 0;
    for(int i = 0; i < decimal.size(); i++){
        if(decimal[i] == '0'){
            k++;
        }
        else{
            break;
        }
    }
    decimal.erase(0, k);
    if(decimal.size() == 0){
        decimal = "0";
    }
    return tmp + decimal;
}
void BigDecimalInt::set_dec(string deci){
    decimal=deci;
    if(equalsZero(decimal)){
        sign = '+';
    }
}

void BigDecimalInt::set_sign(char s) {sign = s;}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec) {
    BigDecimalInt ans;
    string result = "";
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
    string dec2 = anotherDec.getDec(),dec = decimal;
    if(sign == anotherDec.getSign()){
        int sum, carry=0;
        for(int i=dec.length()-1; i>=0; i--){
            sum = (int)dec[i]-'0' + (int)dec2[i]-'0' + carry;
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
    else if(sign != anotherDec.getSign()){
        if(dec == dec2){
            result ="0";
            ans.set_dec(result);
            return result;
        }
        if(sign == '-'){
            if(isSmaller(dec,dec2)){
                swap(dec,dec2);
                }
            else{
                ans.set_sign('-');}
                int carry=0;
                for(int i=decimal.size()-1;i>=0;i--){
                    int sum = (int)dec[i]-(int)dec2[i]-carry;
                    if(sum>=0){
                        carry = 0;
                        result += to_string(sum);
                    }
                    else{
                        carry =1;
                        sum+=10;
                        result+= to_string(sum);
                    }
                }
                reverse(result.begin(),result.end());
               // result.pop_back();
                if(result[0]=='0')
                    result.erase(0,1);
                ans.set_dec(result);
            return ans;

        }
        else if(anotherDec.getSign()=='-'){
            if (isSmaller(dec,dec2)){
                ans.set_sign('-');
                swap(dec,dec2);
            }
            int carry=0;
            for(int i=dec.size();i>=0;i--){
                int sum = (int)dec[i]-(int)dec2[i]-carry;
                if(sum>=0){
                    carry = 0;
                    result += to_string(sum);
                }
                else{
                    carry =1;
                    sum+=10;
                    result+= to_string(sum);
                }
            }
            reverse(result.begin(),result.end());
            result.pop_back();
            if(result[0]=='0'){
                result.erase(0,1);
            }
            ans.set_dec(result);
            return ans;
        }
    }
    return -1;
}

BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec) {
    BigDecimalInt ans;
    string str = "";
    if(decimal.size()<anotherDec.getDec().size()){
        int diff = anotherDec.getDec().size()-decimal.size();
        for(int i=0;i<diff;i++){
            decimal='0'+decimal;
        }
    }
    else if(anotherDec.getDec().size()<decimal.size()){
        int diff = decimal.size() - anotherDec.getDec().size();
        string tmp1 = anotherDec.getDec();
        for(int i=0;i<diff;i++){
            tmp1 = '0'+tmp1;
        }
        anotherDec.set_dec(tmp1);
    }
    string dec = decimal,dec2 = anotherDec.getDec();
    if(sign == anotherDec.getSign()){
        if(isSmaller(dec,dec2)){
            swap(dec,dec2);
            ans.set_sign('-');}
        int carry=0;
        for(int i=dec.size();i>=0;i--){
            int sum = (int)dec[i]-(int)dec2[i]-carry;
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
        if(str[0]=='0')
        str.erase(0,1);
        if((decimal == anotherDec.getDec())&&(sign == '-')){
            sign = '+';
        }
        if(sign=='-'){
            if(ans.getSign()=='-'){
                ans.set_sign('+');
            }
            else if(ans.getSign()!='-'){
                ans.set_sign('-');
            }
        }
        ans.set_dec(str);}
            else{
                if(sign == '-'){
                    ans.set_sign('-');
                }
                int sum, carry=0;
                    for(int i=dec.length()-1; i>=0; i--){
                        sum = (int)dec[i]-'0' + (int)dec2[i]-'0' + carry;
                        if(sum > 9){
                            str = to_string(sum%10) + str;
                            carry = sum/10;
                        }else{
                            str = to_string(sum) + str;
                            carry = 0;
                        }
                    }

                    if(carry != 0){
                        str = to_string(carry) + str;
                    }
                    ans.set_dec(str);
                }
    return ans;
    }


ostream& operator<< (ostream& out, BigDecimalInt bigDec){
    out << bigDec.getFull();
    return out;
}

istream& operator>> (istream& in, BigDecimalInt& bigDec){
    string tmp;
    in >> tmp;
    if(tmp[0] == '-' || tmp[0] == '+'){
        bigDec.set_sign(tmp[0]);
        tmp.erase(0, 1);
        bigDec.set_dec(tmp);
    }
    else{
        bigDec.set_dec(tmp);
        bigDec.set_sign('+');
    }
    return in;
}

bool BigDecimalInt::operator> (BigDecimalInt anotherDec){
    if(sign == '+' && anotherDec.getSign() == '-'){
        return true;
    }
    else if(sign == '-' && anotherDec.getSign() == '+'){
        return false;
    }
    else if(sign == '+' && anotherDec.getSign() == '+'){
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
        string tmp = anotherDec.getDec();
        for(int i = 0; i < decimal.size(); i++){
            if(decimal[i] > tmp[i]){
                return true;
            }
            else if(decimal[i] < tmp[i]){
                return false;
            }
        }
    }
    else{
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
        string tmp = anotherDec.getDec();
        for(int i = 0; i < decimal.size(); i++){
            if(decimal[i] > tmp[i]){
                return false;
            }
            else if(decimal[i] < tmp[i]){
                return true;
            }
        }
    }
    return false;
}

bool BigDecimalInt::operator< (BigDecimalInt anotherDec){
    if(sign == '+' && anotherDec.getSign() == '-'){
        return false;
    }
    else if(sign == '-' && anotherDec.getSign() == '+'){
        return true;
    }
    else if(sign == '+' && anotherDec.getSign() == '+'){
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
        string tmp = anotherDec.getDec();
        for(int i = 0; i < decimal.size(); i++){
            if(decimal[i] > tmp[i]){
                return false;
            }
            else if(decimal[i] < tmp[i]){
                return true;
            }
        }
    }
    else{
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
        string tmp = anotherDec.getDec();
        for(int i = 0; i < decimal.size(); i++){
            if(decimal[i] > tmp[i]){
                return true;
            }
            else if(decimal[i] < tmp[i]){
                return false;
            }
        }
    }
    return false;
}

bool BigDecimalInt::operator== (BigDecimalInt anotherDec) {
    // if(sign == anotherDec.getSign()){
    //     if(decimal == anotherDec.getDec()){
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }
    // }
    // else{
    //     return false;
    // }
    return (getFull() == anotherDec.getFull());
}


