#include "bigDec.h"
#include "bigDec.cpp"

int main(){
BigDecimalInt int1("30");
BigDecimalInt int2 ("-450");
BigDecimalInt int3 = int1 - int2;
cout<<int3.getFull();

}