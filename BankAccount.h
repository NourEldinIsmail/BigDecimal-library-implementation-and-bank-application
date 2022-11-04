#pragma once
#include<iostream>
using namespace std;



class BankAccount {
private:
string ID;
double balance;
public:
BankAccount(){balance = 0.0;}
BankAccount(string id, double bal){ID = id; balance = bal;}
void setID(string id){ID = id;}
void setBalance(double bal){balance = bal;}
string getID(){return ID;}
double getBalance(){return balance;}
virtual  void deposit(double amount){balance += amount;}
virtual  bool withdraw(double amount){
    if (amount > balance) {
        cout << "Insufficient funds" << endl;
        return false;
    } else {
        balance -= amount;
        return true;
    }
}
};


class SavingsAccount : public BankAccount {
private:
double minBalance = 1000.0;
public:
SavingsAccount(string id, double bal) : BankAccount(id, bal){
if (bal < minBalance) {
cout << "Insufficient funds" << endl;
}

}
void setMinBalance(double minBal){minBalance = minBal;}
double getMinBalance(){return minBalance;}
bool withdraw(double amount) {
    if (amount > (getBalance() - minBalance)) {
        cout << "Insufficient funds" << endl;
        return false;
    } else {
        setBalance(getBalance() - amount);
        return true;
    }
}
void deposit(double amount) {
    if(amount >=100){
        setBalance(getBalance() + amount);
    }
    else{
        cout << "Minimum deposit is 100" << endl;
    }
}

};


class client{

};

class BankApplication{



};


