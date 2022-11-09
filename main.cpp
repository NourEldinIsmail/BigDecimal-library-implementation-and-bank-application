#include"bigDec.cpp"
#include"BigReal.cpp"
#include"BankAccount.cpp"
int main() {
   /* BankApplication app;
    app.run();
    return 0;
*/
  BigReal a("2.5");
        BigReal b("-2.9");
        BigReal c = a - b;
        cout << c << endl;
}
