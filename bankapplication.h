#pragma once
#include<iostream>
#include<bits/stdc++.h>
#include"client.h"
#include"BankAccount.h"

class BankApplication{
public:
    void run();
    int displayMenu();
    void displayAccounts();
    void createAccount();
    void deposit();
    void withdraw();
};
