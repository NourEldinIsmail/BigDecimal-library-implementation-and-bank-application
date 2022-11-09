#include "BigReal.h"
BigReal::BigReal(BigReal&&other) {
    cout<<"Move constructor called"<<endl;// Move constructor
    this ->real = other.real;
    other.real = nullptr;
    this -> sign1 = other.sign1;
    other.sign1 = nullptr;
    this -> integer = other.integer;
    other.integer = nullptr;
    this -> fraction = other.fraction;
    other.fraction = nullptr;
}
BigReal::BigReal(const BigReal &other) { // Copy constructor
    // this->real = new string;
    // this->sign1 = new char;
    *(this->real) = *(other.real);
    *(this->sign1) = *(other.sign1);
    *(this->integer) = *(other.integer);
    *(this->fraction) = *(other.fraction);
     cout<<"Copy constructor called"<<endl;
}

// deep copy
BigReal &BigReal::operator=(BigReal &other) { // Assignment operator
      this ->real = new string(*other.real);
      this -> sign1 = new char(*other.sign1);
        this -> integer = new BigDecimalInt(*other.integer);
        this -> fraction = new BigDecimalInt(*other.fraction);
      cout<<"Assignment operator called"<<endl;
       return *this;
}
// move assignment
BigReal &BigReal::operator=(BigReal &&other) { // Move assignment
    this->real = other.real;
    this->sign1 = other.sign1;
    this->integer = other.integer;
    this->fraction = other.fraction;
    other.sign1 = nullptr;
    other.real = nullptr;
    other.integer = nullptr;
    other.fraction = nullptr;
    cout<<"Move assignment called"<<endl;
    return *this;

}

BigReal::BigReal(BigDecimalInt bigInteger) {
    *real = bigInteger.getnum();
    string s = *real;
   if(find(s.begin(),s.end(),'.')==s.end())
    *real += ".0";

    if(bigInteger.Sign() == 1){
        *sign1 = '+';
    }
    else{
        *sign1 = '-';
        *real = '-' + *real;
    }
}
BigReal::BigReal(double realNum) {
    *real = to_string(realNum);
    assign();
}
BigReal::BigReal(string realNumber) {

    if(realNumber.length() == 1){
        realNumber += ".0";
    }
    if(realNumber[0]=='-'){
        *sign1 = '-';
        // realNumber.erase(0,1);
    }
    else if(realNumber[0]=='+') {
        *sign1 = '+';
        realNumber.erase(0, 1);
    }
    else{
        *sign1 = '+';
    }
    if(realNumber[0]=='.'){
        realNumber = "0"+realNumber;
    }
    else if(realNumber[realNumber.length()-1]=='.')
        realNumber += '0';
    *real = realNumber;
    assign();
}
BigReal::~BigReal() {
    if(real!= nullptr)
        delete real;
    if(sign1!= nullptr)
        delete sign1;
    if(integer!= nullptr)
        delete integer;
    if(fraction!= nullptr)
        delete fraction;
    cout<<"Destructor called"<<endl;
}
string* BigReal::get_real() {
    return real;
}

void BigReal::assign() {
    int i = 0;
    while((*real)[i]!='.'){
        i++;
    }
    string integer = real->substr(0,i);
    string fraction = real->substr(i+1,real->length()-i-1);
    for(int i = 0; i < integer.length(); i++){
        if(integer[i] == '0'){
            integer.erase(0,1);
            i--;
        }
        else
            break;
    }
    for(int i = fraction.length()-1; i >= 0; i--){
        if(fraction[i] == '0'){
            fraction.erase(i,1);
        }
        else
            break;
    }
    if(integer.length() == 0)
        integer = "0";
    if(fraction.length() == 0)
        fraction = "0";

    *real = integer + "." + fraction;
    *this->integer = BigDecimalInt(integer);
    *this->fraction = BigDecimalInt(fraction);
}

BigReal BigReal::operator+(BigReal &other) {

    string ref1 = *(this->real);
    string ref2 = *(other.real);
    if(ref1[0]=='-')
        ref1.erase(0,1);
    if(ref2[0]=='-')
        ref2.erase(0,1);
    string real1="",fraction1="",real2="",fraction2="";
int cnt1=0,cnt2=0;
    for(int i = 0; i < ref1.length(); i++){
        if(cnt1 == 0){
            real1 += ref1[i];
        }
        if(ref1[i] == '.'){
            ref1.erase(i,1);
            cnt1++;
        }
        if(cnt1>0){
            fraction1 += ref1[i];}
    }
    for(int i = 0; i < ref2.length(); i++){
        if(cnt2 == 0){
            real2 += ref2[i];
        }
        if(ref2[i] == '.'){
            ref2.erase(i,1);
            cnt2++;
        }
        if(cnt2>0){
            fraction2 += ref2[i];}
        }
while(real1.length() <real2.length()){
    real1 = '0' + real1;
}
while(real2.length() <real1.length()){
    real2 = '0' + real2;
}
while(fraction1.length() <fraction2.length()){
    fraction1 = fraction1 + '0';
}
while(fraction2.length() <fraction1.length()){
    fraction2 = fraction2 + '0';
}
ref1 = real1 + fraction1;
ref2 = real2 + fraction2;
for(int i = 0; i < ref1.length(); i++){
    if(ref1[i] == '.'){
      ref1.erase(i,1);
      break;
    }
}
for(int i = 0; i < ref2.length(); i++){
    if(ref2[i] == '.'){
      ref2.erase(i,1);
      break;
    }
}
int pnt_index = ref1.length()-fraction1.length();
if(*(this->sign1) == '-')
    ref1 = '-' + ref1;

if(*(other.sign1) == '-')
    ref2 = '-' + ref2;

BigDecimalInt int1(ref1);
BigDecimalInt int2(ref2);
  string s1 = int1.getnum(),s2 = int2.getnum();
  BigDecimalInt int3 = int1 + int2;
  string r = int3.getnum();
  string s = "";

  if(int1.Sign() != int2.Sign() && real1 == real2){
     s  = "0."+r;
  }
  else{
    for(int i=0;i<r.length();i++){
        if(i==pnt_index){
            s += '.';
            s += r[i];}
        else{
            s += r[i];
        }
    }}

  if(find(s.begin(),s.end(),'.')==s.end())
  {s  = "0."+s;}
    BigReal result(s);
  if(int3.Sign() == 1) {
      *result.sign1 = '+';
  }
    else{
        *result.sign1 = '-';}

    return result;
}

bool BigReal::operator< (BigReal anotherReal){
    if(this->sign1 == anotherReal.sign1){
        if(*(this->sign1) == '+'){
            if(this->integer < anotherReal.integer){
                return true;
            }
            else if(this->integer == anotherReal.integer){
                if(this->fraction < anotherReal.fraction){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else{
            if(this->integer > anotherReal.integer){
                return true;
            }
            else if(this->integer == anotherReal.integer){
                if(this->fraction > anotherReal.fraction){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    else{
        if(*(this->sign1) == '+'){
            return false;
        }
        else{
            return true;
        }
    }
}

bool BigReal::operator> (BigReal anotherReal){
    if(this->sign1 == anotherReal.sign1){
        if(*(this->sign1) == '+'){
            if(this->integer > anotherReal.integer){
                return true;
            }
            else if(this->integer == anotherReal.integer){
                if(this->fraction > anotherReal.fraction){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else{
            if(this->integer < anotherReal.integer){
                return true;
            }
            else if(this->integer == anotherReal.integer){
                if(this->fraction < anotherReal.fraction){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    else{
        if(*(this->sign1) == '+'){
            return true;
        }
        else{
            return false;
        }
    }
}

bool BigReal::operator== (BigReal anotherReal){
    return *(this->real) == *(anotherReal.real);
}

int BigReal::sign() {
    if(*sign1 == '+'){
        return 1;
    }
    else{
        return -1;
    }
}

int BigReal::size(){
    return fraction->size() + integer->size();
}

ostream& operator << (ostream &out, BigReal num){
    if(num.sign() == -1){
        out << "-";
    }
    out<<*(num.real)<<endl;
    return out;
}

istream& operator>> (istream &in, BigReal &num){
    in>>*(num.real);
    num.assign();
    return in;
}

BigReal BigReal::operator-(BigReal &other) {
    string ref1 = *(this->real);
    string ref2 = *(other.real);
    if(ref1[0]=='-')
        ref1.erase(0,1);
    if(ref2[0]=='-')
        ref2.erase(0,1);
    string real1="",fraction1="",real2="",fraction2="";
    int cnt1=0,cnt2=0;
    for(int i = 0; i < ref1.length(); i++){
        if(cnt1 == 0){
            real1 += ref1[i];
        }
        if(ref1[i] == '.'){
            ref1.erase(i,1);
            cnt1++;
        }
        if(cnt1>0){
            fraction1 += ref1[i];}
    }
    for(int i = 0; i < ref2.length(); i++){
        if(cnt2 == 0){
            real2 += ref2[i];
        }
        if(ref2[i] == '.'){
            ref2.erase(i,1);
            cnt2++;
        }
        if(cnt2>0){
            fraction2 += ref2[i];}
    }
    while(real1.length() <real2.length()){
        real1 = '0' + real1;
    }
    while(real2.length() <real1.length()){
        real2 = '0' + real2;
    }
    while(fraction1.length() <fraction2.length()){
        fraction1 = fraction1 + '0';
    }
    while(fraction2.length() <fraction1.length()){
        fraction2 = fraction2 + '0';
    }
    ref1 = real1 + fraction1;
    ref2 = real2 + fraction2;
    for(int i = 0; i < ref1.length(); i++){
        if(ref1[i] == '.'){
            ref1.erase(i,1);
            break;
        }
    }
    for(int i = 0; i < ref2.length(); i++){
        if(ref2[i] == '.'){
            ref2.erase(i,1);
            break;
        }
    }
    int pnt_index = ref1.length()-fraction1.length();
    if(*(this->sign1) == '-')
        ref1 = '-' + ref1;

    if(*(other.sign1) == '-')
        ref2 = '-' + ref2;

    BigDecimalInt int1(ref1);
    BigDecimalInt int2(ref2);
    string s1 = int1.getnum(),s2 = int2.getnum();
    BigDecimalInt int3 = int1 - int2;
    string r = int3.getnum();
    string s = "";

    if(int1.Sign() == int2.Sign() && real1 == real2){
        s  = "0."+r;
    }
    else{
        for(int i=0;i<r.length();i++){
            if(i==pnt_index){
                s += '.';
                s += r[i];}
            else{
                s += r[i];
            }
        }}

    if(find(s.begin(),s.end(),'.')==s.end())
    {s  = "0."+s;}
    BigReal result(s);
    if(int3.Sign() == 1) {
        *result.sign1 = '+';
    }
    else{
        *result.sign1 = '-';}

    return result;
}


