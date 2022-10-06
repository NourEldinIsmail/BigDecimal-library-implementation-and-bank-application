#include "bigDec.h"
#include "bigDec.cpp"

int main(){
BigDecimalInt int1("1234567890123");
BigDecimalInt int2 ("113");
BigDecimalInt int3 = int1 + int2;
cout<<int3.getDec();

}