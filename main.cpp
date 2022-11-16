#include"bigDec.cpp"
#include"BigReal.cpp"
#include"BankAccount.cpp"
int main() {
  // BankApplication app;
  // app.run();
  BigReal a("-2.5696");
  BigReal b("-22.9");
  BigReal c = a - b;
  cout << c << endl;
  return 0;

}
