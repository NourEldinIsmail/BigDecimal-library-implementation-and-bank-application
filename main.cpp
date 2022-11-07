#include"bigDec.cpp"
#include"BigReal.cpp"
#include"BankAccount.cpp"
int main() {
   /* BankApplication app;
    app.run();
    return 0;
*/
  BigReal a("1.3");
        BigReal b("1.2");
        BigReal c = a + b;
        cout << c << endl;
}
