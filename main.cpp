#include"bigDec.cpp"
#include"BigReal.cpp"
int main(){

    BigReal b("0.1");
    BigReal c(b);
    b = BigReal("0.2");
    cout<<*(b.get_real())<<endl;
    cout<<*(c.get_real())<<endl;

/*BigReal c(std::move(BigReal("1.2")));
cout<<*(c.get_real())<<endl;*/


}