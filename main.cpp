#include "bigDec.h"
#include "bigDec.cpp"

int main(){
BigDecimalInt int1("98");
BigDecimalInt int2 ("987");
BigDecimalInt int3 = int1 + int2;
cout<<int3.getDec();
}