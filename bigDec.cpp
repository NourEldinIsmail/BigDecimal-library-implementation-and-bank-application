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
    if(sign == anotherDec.getSign()){
        int sum, carry=0;
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
    else if(sign != anotherDec.getSign()){
        if(sign == '-'){
            string tmp = anotherDec.getDec();
            if(isSmaller(decimal,tmp)){
                swap(decimal,tmp);
                anotherDec.set_dec(tmp);
                }
            else{
                ans.set_sign('-');}
            string tmp1 = anotherDec.getDec();
                int carry=0;
                for(int i=tmp1.size();i>=0;i--){
                    int sum = (int)decimal[i]-(int)tmp1[i]-carry;
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
                if(result[0]=='0')
                    result.erase(0,1);
                ans.set_dec(result);
            return ans;

        }
        else if(anotherDec.getSign()=='-'){
            string s = anotherDec.getDec();
            if (isSmaller(decimal,s)){
                ans.set_sign('-');
                swap(decimal,s);
                anotherDec.set_dec(s);
            }
            string tmp2 = anotherDec.getDec();
            int carry=0;
            for(int i=tmp2.size();i>=0;i--){
                int sum = (int)decimal[i]-(int)tmp2[i]-carry;
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
        string tmp = anotherDec.getDec();
        for(int i=0;i<diff;i++){
            tmp = '0'+tmp;
        }
        anotherDec.set_dec(tmp);
    }
    if(sign == anotherDec.getSign()){
        if(isSmaller(decimal,anotherDec.getDec())){
            string tmp = anotherDec.getDec();
            swap(decimal,tmp);
            anotherDec.set_dec(tmp);
            ans.set_sign('-');}

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
                    string t = anotherDec.getDec();
                    for(int i=decimal.length()-1; i>=0; i--){
                        sum = (int)decimal[i]-'0' + (int)t[i]-'0' + carry;
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


