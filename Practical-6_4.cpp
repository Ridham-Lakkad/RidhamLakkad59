#include<iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base class constructor called.." << endl;
    }

    virtual ~Base()
    {
        cout << "Base class virtual destructor called.." << endl;
    }
};

class Derived : public Base
{
    int* data;
public:
    Derived()
    {
        data = new int[5];
        cout << "Derived class constructor called.." << endl;
    }

    ~Derived()
    {
        cout << "Derived class destructor called.." << endl;
    }
};

int main()
{
    Base *base_ptr = new Derived();

    delete base_ptr;

    cout << endl;
    cout << "\nRIDHAM LAKKAD : 24CE059" << endl;

    return 0;
}