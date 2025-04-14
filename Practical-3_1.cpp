#include <iostream>
#include <vector>

using namespace std;

class employee
{
    string name;
    double salary, bonus, total_salary;

public:

    employee(string n = "Unknown", double s = 2000, double b = 1000)
        : name(n), salary(s), bonus(b)
    {
        calculate_salary();
    }

    void calculate_salary()
    {
        total_salary = salary + bonus;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total salary: " << total_salary << endl;
        cout << "----------------------------" << endl;
    }
};

int main()
{
    vector<employee> emp;

    emp.push_back(employee("Ridham Lakkad", 5000, 2000));
    emp.push_back(employee("Rishi Hirapara", 7000, 3000));

    for (auto &i : emp)
    {
        i.display();
    }

    cout << endl;
    cout << "Ridham Lakkad : 24CE059" << endl;

    return 0;
}
