#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    string accountNumber;
    double balance;

public:
    BankAccount(string name, string accNumber, double initialBalance = 0.0) {
        accountHolderName = name;
        accountNumber = accNumber;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Error: Deposit amount must be positive." << endl;
            return;
        }

        balance += amount;
        cout << "Deposited $" << amount << " successfully." <<endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Withdrawal amount must be positive." <<endl;
            return;
        }

        if (amount > balance) {
            cout << "Error: Insufficient funds. Current balance is $" << balance <<endl;
            return;
        }

        balance -= amount;
        cout << "Withdrew $" << amount << " successfully." <<endl;
    }

    void display_balance() const {
        cout << "Account Information:" << endl;
        cout << "Holder: " << accountHolderName <<endl;
        cout << "Account Number: " << accountNumber <<endl;
        cout << "Current Balance: $" << balance <<endl;
    }

    string get_account_holder() const {
        return accountHolderName;
    }

    string get_account_number() const {
        return accountNumber;
    }

    double get_balance() const {
        return balance;
    }
};

int main() {
    BankAccount account1("John Doe", "A12345", 1000.0);
    BankAccount account2("Jane Smith", "B67890", 500.0);
    BankAccount account3("Alice Johnson", "C13579");

    cout << "Initial Account States:" <<endl;
    cout << "-------------------------" <<endl;
    account1.display_balance();
    cout << "-------------------------" <<endl;
    account2.display_balance();
    cout << "-------------------------" <<endl;
    account3.display_balance();
    cout << "-------------------------\n" <<endl;

    cout << "Operations on " << account1.get_account_holder() << "'s account:" << endl;
    account1.deposit(250.0);
    account1.withdraw(100.0);
    account1.display_balance();
    cout << "-------------------------\n" <<endl;

    cout << "Operations on " << account2.get_account_holder() << "'s account:" <<endl;
    account2.withdraw(600.0);
    account2.deposit(300.0);
    account2.withdraw(400.0);
    account2.display_balance();
    cout << "-------------------------\n" <<endl;

    cout << "Operations on " << account3.get_account_holder() << "'s account:" <<endl;
    account3.deposit(-50.0);
    account3.deposit(1000.0);
    account3.withdraw(200.0);
    account3.display_balance();
    cout << "-------------------------" <<endl;

    return 0;
}
