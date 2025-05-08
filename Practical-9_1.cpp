#include <iostream>
#include <stdexcept> 
#include <limits>    
#include <string>
#include <sstream>   
using namespace std;

class InvalidInputException : public runtime_error {
public:
    InvalidInputException(const string& message) : runtime_error(message) {}
};

float getValidFloatInput(const string& prompt) {
    string input;
    float value;

    while (true) {
        cout << prompt;
        getline(cin, input);
        stringstream ss(input);
        
        if (ss >> value && ss.eof()) {
            return value;
        } else {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    }
}

int main() {
    try {
        float loanAmount = getValidFloatInput("Enter the loan amount: ");
        float annualIncome = getValidFloatInput("Enter your annual income: ");

        if (annualIncome == 0) {
            throw InvalidInputException("Income cannot be zero. Division by zero is not allowed.");
        }

        float ratio = loanAmount / annualIncome;
        
        cout << "The loan-to-income ratio is: " << ratio << endl;
    }
    catch (const InvalidInputException& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "An unexpected error occurred: " << e.what() << endl;
    }

    cout << "\nRIDHAM LAKKAD : 24CE059\n";

    return 0;
}