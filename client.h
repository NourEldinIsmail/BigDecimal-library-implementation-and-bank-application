#pragma once
#include<iostream>
#include<bits/stdc++.h>
#include"bankaccount.h"
using namespace std;

class BankAccount;

class Client{
private:
    string name, address, phoneNumber;
    int accType;
public:
    BankAccount* account;
    Client() = default;
    Client(string n, string a, string p, int t){
        // name = n, address = a, phoneNumber = p, accType = t;
        swap(name, n);
        swap(address, a);
        swap(phoneNumber, p);
        swap(accType, t);
    }
    string get_name(){return name;}
    string get_address(){return address;}
    string get_phone(){return phoneNumber;}
    void createAcount(const string &id, double bal);
    int get_accType(){return accType;}
};
