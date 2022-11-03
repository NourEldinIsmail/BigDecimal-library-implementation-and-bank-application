#include"bigDec.cpp"
#include"BigReal.cpp"
int main(){
    BigReal int1("123.456");
    BigReal int2("123.456");
    BigReal int3 = int1 - int2;
    cout << *(int3.get_real()) << endl;


}