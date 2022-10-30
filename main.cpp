#include"bigDec.cpp"
#include"BigReal.cpp"
int main(){

    BigReal b("-.1");
cout<<*(b.get_real())<<endl;
/*BigReal c(std::move(BigReal("1.2")));
cout<<*(c.get_real())<<endl;*/


}