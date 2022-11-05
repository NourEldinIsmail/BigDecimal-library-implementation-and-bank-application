#include "BankAccount.h"

void BankApplication::run(){
    while(true){
        int x = BankApplication::displayMenu();
        switch (x)
        {
        case 1:
            BankApplication::createAccount();
            break;
        
        case 2:
            BankApplication::displayAccounts();
            break;

        case 5:
            return;
            break;
        
        default:
            break;
        }
    }
}

int BankApplication::displayMenu(){
    int choice;
    cout << "1. Create a new account" << endl;
    cout << "2. List Clients and Accounts" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Withdraw" << endl;
    cout << "5. Exit" << endl;
    cout << "Please Enter Choice =========> ";
    cin >> choice;
    cout << endl;
    return choice;
}

void BankApplication::createAccount(){
    string name, address, phone;
    int accType;
    double startingBalance;
    cout << "Please Enter Client Name =========> ";
    cin.ignore();
    getline(cin, name);
    cout << endl;
    cout << "Please Enter Client Address =========> ";
    cin.ignore();
    getline(cin, address);
    cout << endl;
    cout << "Please Enter Client Phone =========> ";
    cin.ignore();
    getline(cin, phone);
    cout << endl;
    cout << "What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 =========> ";
    cin >> accType;
    cout << endl;
    if(accType == 2){
        while(true){
            cout << "Please Enter the Starting Balance =========> ";
            cin >> startingBalance;
            cout << endl;
            if(startingBalance >= 1000){
                break;
            }
            else{
                cout << "Minimum Balance is 1000" << endl;
            }
        }
    }
    else{
        cout << "Please Enter the Starting Balance =========> ";
        cin >> startingBalance;
        cout << endl;
    }
    Client c(name, address, phone, accType);
    string id = "FCAI-" + to_string(++lastID);
    c.createAcount(id, startingBalance);
    clients[id] = c;
    ids.push_back(id);
    cout << "An account was created with ID " <<  id << " and Starting Balance " << startingBalance  << " L.E." << endl;
}

void Client::createAcount(string id, double bal){
    if(accType == 1){
        BankAccount ac(id, bal);
        BankAccount* account = &ac;
        accounts[id] = ac;
    }
    else if(accType == 2){
        SavingsAccount ac(id, bal);
        SavingsAccount* account = &ac;
        accounts[id] = ac;
    }

}

void BankApplication::displayAccounts(){
    for(string id:ids){
        cout << "-------------------------- " << clients[id].get_name() << " ---------" << endl;
        cout << "Address: " << clients[id].get_address() << endl;
        cout << "Account ID: " << id;
        if(clients[id].get_accType() == 1){
            cout << " (Basic)" << endl;
        }
        else if(clients[id].get_accType() == 2){
            cout << " (Saving)" << endl;
        }
        cout << "Balance: " << accounts[id].getBalance() << endl;
    }
}

