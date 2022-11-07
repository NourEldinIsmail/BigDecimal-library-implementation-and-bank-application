#include"bigDec.cpp"
#include"BigReal.cpp"
#include"BankAccount.cpp"
int main() {
   /* BankApplication app;
    app.run();
    return 0;
*/
  BigReal a("-123.456");
        BigReal b("123.456");
        BigReal c = a + b;
        cout << c << endl;
}
