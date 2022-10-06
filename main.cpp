#include "bigDec.h"
#include "bigDec.cpp"

int main(){
BigDecimalInt int1("-2007558");
BigDecimalInt int2 ("5778877");
BigDecimalInt int3 = int1 + int2;
cout<<int3.getFull();

}