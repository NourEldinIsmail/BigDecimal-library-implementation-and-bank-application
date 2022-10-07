#include "bigDec.h"
#include "bigDec.cpp"

int main(){
    while(true){
        BigDecimalInt int4("-00025525");
        cout << int4;
        BigDecimalInt int1;
        BigDecimalInt int2;
        cin >> int1 >> int2;
        BigDecimalInt int3 = int1 - int2;
        cout << int3.getFull() << endl << (int1 - int2) << endl;
        cout << (int1 < int2) << endl;
        
    }
}