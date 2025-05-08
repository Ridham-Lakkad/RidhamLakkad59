#include <iostream>
#include <stdexcept> 
#include <string>
#include <sstream>   
using namespace std;

class TransactionHistory {
private:
    string* transactions;
    int capacity;
    int size;

    void resize() {
        capacity *= 2;
        string* new_transactions = new string[capacity];
        for (int i = 0; i < size; ++i) {
            new_transactions[i] = transactions[i];
        }
        delete[] transactions;
        transactions = new_transactions;
    }

public:
    TransactionHistory() : capacity(10), size(0) {
        transactions = new string[capacity];
    }

    ~TransactionHistory() {
        delete[] transactions;
    }

    void log(const string& transaction) {
        if (size == capacity) {
            resize();
        }
        transactions[size++] = transaction;
    }

    void printHistory() const {
        cout << "\nTransaction History:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << transactions[i] << endl;
        }
    }
};

class BankAccount {
private:
    string accountHolder;
    float balance;
    TransactionHistory transactionHistory;

public:
    BankAccount(const string& name, float initialBalance = 0.0) 
        : accountHolder(name), balance(initialBalance) {}

    void deposit(float amount) {
        try {
            if (amount <= 0) {
                throw invalid_argument("Error: Deposit amount must be greater than zero.");
            }
            balance += amount;
            stringstream transaction;
            transaction << "Deposited: ₹" << amount;
            transactionHistory.log(transaction.str());
            cout << "Deposit successful!" << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }

    void withdraw(float amount) {
        try {
            if (amount <= 0) {
                throw invalid_argument("Error: Withdrawal amount must be greater than zero.");
            }
            if (amount > balance) {
                throw runtime_error("Error: Insufficient funds.");
            }
            balance -= amount;
            stringstream transaction;
            transaction << "Withdrew: ₹" << amount;
            transactionHistory.log(transaction.str());
            cout << "Withdrawal successful!" << endl;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
        catch (const runtime_error& e) {
            cout << e.what() << endl;
        }
    }

    float getBalance() const {
        return balance;
    }

    void printTransactionHistory() const {
        transactionHistory.printHistory();
    }

    void accountDetails() const {
        cout << "\nAccount Holder: " << accountHolder << endl;
        cout << "Current Balance: ₹" << balance << endl;
    }
};

int main() {
    BankAccount account("RIDHAM LAKKAD", 5000);

    account.accountDetails(); 

    account.deposit(1500);  
    account.deposit(-200); 
    account.withdraw(2000); 
    account.withdraw(10000); 
    account.withdraw(-500);  

    account.accountDetails();
    account.printTransactionHistory();

    cout << "\nEnd of Program" << endl;
    cout<<"\nRIDHAM LAKKAD : 24CE059\n";
    return 0;
}