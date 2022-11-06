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
            case 3:
                BankApplication::deposit();
                break;
            case 4:
                BankApplication::withdraw();
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
    string id = "FCAI-" + to_string(++lastID);
    Client c(name, address, phone, accType);
    c.createAcount(id, startingBalance);
    clients[id] = c;
    ids.push_back(id);
    cout << "An account was created with ID " <<  id << " and Starting Balance " << startingBalance  << " L.E." << endl;
}

void Client::createAcount(string id, double bal){
    if(accType == 1){
        account = new BankAccount(id, bal);
        accounts[id] = account;
    }
    else if(accType == 2){
        account = new SavingsAccount(id, bal);
        accounts[id] = account;
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
        cout << "Balance: " << accounts[id]->getBalance() << endl;
        cout << "ID: " << accounts[id]->getID() << endl;
    }
}

void BankApplication::deposit() {
    string id;
    double amount;
    cout << "Please Enter Account ID =========> ";
    cin >> id;
    cout << endl;
    cout << "Please Enter Amount =========> ";
    cin >> amount;
    while (amount < 100) {
        cout << "Minimum deposit is 100" << endl;
        cout << "Please Enter Amount =========> "<<endl;
        cin >> amount;
    }
    accounts[id]->deposit(amount);
    cout << "Deposit was successful" << endl;
    cout<<"Your new balance is "<<accounts[id]->getBalance()<<endl;

}
void BankApplication::withdraw() {
    string id;
    double amount;
    cout << "Please Enter Account ID =========> ";
    cin >> id;
    cout << endl;
    cout << "Please Enter Amount =========> ";
    cin >> amount;
    while (amount>accounts[id]->getBalance()) {
        cout << "You don't have enough balance" << endl;
        cout << "Please Enter Amount =========> "<<endl;
        cin >> amount;
    }
    accounts[id]->withdraw(amount);
    cout << "Withdraw was successful" << endl;
    cout<<"Your balance is "<<accounts[id]->getBalance()<<endl;


}


