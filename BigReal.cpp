#include "BigReal.h"
BigReal::BigReal(BigReal &&other) {  // Move constructor
    real = other.real;
    realNumber = other.realNumber;
    other.real = nullptr;
    other.realNumber = 0.0;
}
BigReal::BigReal(const BigReal &other) { // Copy constructor
    real = other.real;
    realNumber = other.realNumber;
}

// deep copy
BigReal &BigReal::operator=(BigReal &other) { // Assignment operator
    real = other.real;
    realNumber = other.realNumber;
    return *this;
}
// move assignment
BigReal &BigReal::operator=(BigReal &&other) { // Move assignment
    real = other.real;
    realNumber = other.realNumber;
    other.real = nullptr;
    other.realNumber = 0.0;
    return *this;
}
BigReal::BigReal(string realNumber) {

}
BigReal::BigReal(BigDecimalInt bigInteger) {

}
BigReal::BigReal(double realNumber) {
    this->realNumber = realNumber;
    real = to_string(realNumber);
}
