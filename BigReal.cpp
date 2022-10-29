#include "BigReal.h"
BigReal::BigReal(BigReal&&other) {  // Move constructor
    real = other.real;
    other.real = nullptr;
}
BigReal::BigReal(const BigReal &other) { // Copy constructor
    real = new string;
     *real =(*other.real);
}

// deep copy
BigReal &BigReal::operator=(BigReal &other) { // Assignment operator
      real = new string(*other.real);
       return *this;
}
// move assignment
BigReal &BigReal::operator=(BigReal &&other) { // Move assignment
    real = other.real;
    other.real = nullptr;
    return *this;
}
BigReal::BigReal(string realNumber) {
*real = realNumber;
}
BigReal::BigReal(BigDecimalInt bigInteger) {

}
BigReal::BigReal(double realNum) {
    *real = to_string(realNum);
}

