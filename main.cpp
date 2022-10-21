#include "bigDec.h"
#include "bigDec.cpp"

int main(){
    BigDecimalInt int1("-9999");
    BigDecimalInt int2 ("9999");
     if(int1 == int2){
         cout << "Sa7" << endl;
     }
     else{
         cout << "Ghalat" << endl;
     }

    cout << int1.size() << endl;
    cout << int2.size() << endl;

}







