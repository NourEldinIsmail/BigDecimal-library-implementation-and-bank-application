#include "BigReal.h"
BigReal::BigReal(BigReal&&other) {
    cout<<"Move constructor called"<<endl;// Move constructor
    this ->real = other.real;
    other.real = nullptr;
}
BigReal::BigReal(const BigReal &other) { // Copy constructor
    this->real = new string;
     *(this->real) = *(other.real);
     cout<<"Copy constructor called"<<endl;
}

// deep copy
BigReal &BigReal::operator=(BigReal &other) { // Assignment operator
      this ->real = new string(*other.real);
      cout<<"Assignment operator called"<<endl;
       return *this;
}
// move assignment
BigReal &BigReal::operator=(BigReal &&other) { // Move assignment
    this->real = other.real;
    other.real = nullptr;
    cout<<"Move assignment called"<<endl;
    return *this;

}

BigReal::BigReal(BigDecimalInt bigInteger) {

}
BigReal::BigReal(double realNum) {
    *real = to_string(realNum);
}
BigReal::BigReal(string realNumber) {
    if(realNumber[0]=='.'){
        realNumber = "0"+realNumber;
    }
    else if(realNumber[realNumber.length()-1]=='.')
        realNumber += '0';
    *real = realNumber;
}
BigReal::~BigReal() {
    delete real;
    cout<<"Destructor called"<<endl;
}
string* BigReal::get_real() {
    return real;
}

