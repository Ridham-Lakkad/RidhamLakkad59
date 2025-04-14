#include <iostream>
#include <cmath>
using namespace std;

class Loan {
    int loanID;
    string applicant;
    double principal;
    double annualRate;
    int tenureMonths;
public:
    Loan(int id, string name, double p, double rate, int tenure):
         loanID(id), applicant(name), principal(p), annualRate(rate), tenureMonths(tenure) {}

    double calculateEMI() {
        double r = annualRate / 1500.0;
        return (principal * r * pow(1 + r, tenureMonths)) / (pow(1 + r, tenureMonths) - 1);
    }
    void display() {
        cout << "Loan ID: " << loanID << ", Applicant: " << applicant
             << ", Principal: " << principal << ", EMI: " << calculateEMI() << endl;
    }
};

int main(){
    Loan l1(101, "Rishi", 100000, 14, 29);
    l1.display();

     cout<<"Ridham Lakkad:24CE059"<<endl;
    return 0;
}
