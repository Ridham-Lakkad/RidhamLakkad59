#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountHolderName;
    std::string accountNumber;
    double balance;

public:
    BankAccount(const std::string& name, const std::string& accNumber, double initialBalance = 0.0) {
        accountHolderName = name;
        accountNumber = accNumber;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Error: Deposit amount must be positive." << std::endl;
            return;
        }

        balance += amount;
        std::cout << "Deposited $" << amount << " successfully." << std::endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Error: Withdrawal amount must be positive." << std::endl;
            return;
        }

        if (amount > balance) {
            std::cout << "Error: Insufficient funds. Current balance is $" << balance << std::endl;
            return;
        }

        balance -= amount;
        std::cout << "Withdrew $" << amount << " successfully." << std::endl;
    }

    void display_balance() const {
        std::cout << "Account Information:" << std::endl;
        std::cout << "Holder: " << accountHolderName << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Current Balance: $" << balance << std::endl;
    }

    std::string get_account_holder() const {
        return accountHolderName;
    }

    std::string get_account_number() const {
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

    std::cout << "Initial Account States:" << std::endl;
    std::cout << "-------------------------" << std::endl;
    account1.display_balance();
    std::cout << "-------------------------" << std::endl;
    account2.display_balance();
    std::cout << "-------------------------" << std::endl;
    account3.display_balance();
    std::cout << "-------------------------\n" << std::endl;

    std::cout << "Operations on " << account1.get_account_holder() << "'s account:" << std::endl;
    account1.deposit(250.0);
    account1.withdraw(100.0);
    account1.display_balance();
    std::cout << "-------------------------\n" << std::endl;

    std::cout << "Operations on " << account2.get_account_holder() << "'s account:" << std::endl;
    account2.withdraw(600.0);
    account2.deposit(300.0);
    account2.withdraw(400.0);
    account2.display_balance();
    std::cout << "-------------------------\n" << std::endl;

    std::cout << "Operations on " << account3.get_account_holder() << "'s account:" << std::endl;
    account3.deposit(-50.0);
    account3.deposit(1000.0);
    account3.withdraw(200.0);
    account3.display_balance();
    std::cout << "-------------------------" << std::endl;

    return 0;
}
