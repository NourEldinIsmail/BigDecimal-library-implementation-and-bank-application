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
    getline(cin, address);
    cout << endl;
    cout << "Please Enter Client Phone =========> ";
    getline(cin, phone);
    cout << endl;
    cout << "What Type of Account Do You Like? (1) Basic (2) Saving – Type 1 or 2 =========> ";
    cin >> accType;
    cout << endl;
    cout << "Please Enter the Starting Balance =========> ";
    cin >> startingBalance;
    cout << endl;
    Client c(name, address, phone, accType);
    string id = "FCAI-" + to_string(lastID++);
    c.createAcount(id, startingBalance);
    clients[id] = c;
    ids.push_back(id);
    cout << "An account was created with ID " <<  id << " and Starting Balance " << startingBalance  << " L.E." << endl;
}

void Client::createAcount(string id, double bal){
    if(accType == 1){
        BankAccount* account = new BankAccount(id, bal);
        accounts[id] = *account, accType;
    }
    else if(accType == 2){
        SavingsAccount* account = new SavingsAccount(id, bal);
        accounts[id] = *account, accType;
    }

}

void BankApplication::displayAccounts(){
    for(string id:ids){
        cout << "-------------------------- " << clients[id].get_name() << " ---------" << endl;
        cout << "Address: " << clients[id].get_address() << endl;
        cout << "Account ID: " << id << endl;
        if(clients[id].get_accType() == 1){
            cout << " (Basic)" << endl;
        }
        else if(clients[id].get_accType() == 2){
            cout << " (Saving)" << endl;
        }
        cout << "Balance: " << accounts[id].getBalance() << endl;
    }
}

