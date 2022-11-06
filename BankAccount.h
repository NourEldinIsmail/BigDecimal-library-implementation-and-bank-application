#pragma once
#include<iostream>
#include<bits/stdc++.h>
using namespace std;



class BankAccount {
private:
    string ID;
    double balance;
    // Client* owner;
public:
    BankAccount(){balance = 0.0;}
    BankAccount(string id, double bal){ID = id; balance = bal;}
    void setID(string id){ID = id;}
    void setBalance(double bal){balance = bal;}
    string getID(){return ID;}
    double getBalance(){return balance;}
    virtual  void deposit(double amount){balance += amount;}
    virtual  void withdraw(double amount){
        if (amount > balance) {
            cout << "Insufficient funds" << endl;
        } else {
            balance -= amount;

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
    void withdraw(double amount) {
        if (amount > (getBalance() - minBalance)) {
            cout << "Insufficient funds" << endl;
        } else {
            setBalance(getBalance() - amount);
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


class Client{
private:
    string name, address, phoneNumber;
    BankAccount* account;
    int accType;
public:
    Client(){};
    Client(string n, string a, string p, int t){
        name = n, address = a, phoneNumber = p, accType = t;
    }
    string get_name(){return name;}
    string get_address(){return address;}
    string get_phone(){return phoneNumber;}
    void createAcount(string id, double bal);
    int get_accType(){return accType;}
};

class BankApplication{
public:
    void run();
    int displayMenu();
    void displayAccounts();
    void createAccount();
    void deposit();
    void withdraw();
};


map<string, Client> clients;
map<string, BankAccount*> accounts;
vector<string> ids;
int lastID = 0;