#include"bigDec.cpp"
#include"BigReal.cpp"
int main(){
//BigReal a("1.2");
BigReal b("1.2");
BigReal c(std::move(b));
cout<<*(c.get_real())<<endl;

}