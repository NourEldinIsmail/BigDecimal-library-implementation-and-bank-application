#pragma once
#include<iostream>
#include<bits/stdc++.h>
#include"client.h"
#include"bankapplication.h"

using namespace std;

class client;

class BankAccount {
private:
    string ID;
    double balance;
    Client* owner;
public:
    BankAccount(){balance = 0.0;}
    BankAccount(string id, double bal, Client *o){
        // ID = id; balance = bal;
        swap(ID, id);
        swap(balance, bal);
        owner = o;
    }
    void setID(string &id){
        //ID = id;
        ID = move(id);
    }
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
    SavingsAccount(string id, double bal, Client* owner) : BankAccount(id, bal, owner){
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


map<string, Client> clients;
map<string, BankAccount*> accounts;
vector<string> ids;
int lastID = 0;