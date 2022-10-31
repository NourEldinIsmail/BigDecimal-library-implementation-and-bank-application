#include"bigDec.cpp"
#include"BigReal.cpp"
int main(){

    BigReal a(15.3);
    BigReal b(16.0);
    BigReal c = a + b;
    cout << c << endl;

/*BigReal c(std::move(BigReal("1.2")));
cout<<*(c.get_real())<<endl;*/


}