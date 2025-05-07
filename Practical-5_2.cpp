#include <iostream>

class Complex
{
private:
    double real;
    double imag;

public:
    
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) 
    {}

    
    Complex operator+(const Complex& other) const 
    {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const 
    {
        return Complex(real - other.real, imag - other.imag);
    }

    friend std::istream& operator>>(std::istream& in, Complex& c) 
    {
        std::cout << "Enter real part: ";
        in >> c.real;
        std::cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Complex& c) 
    {
        out << c.real;
        if (c.imag >= 0)
            out << " + " << c.imag << "i";
        else
            out << " - " << -c.imag << "i";
        return out;
    }
};

int main() 
{
    Complex c1, c2;
    std::cout << "Enter first complex number:\n";
    std::cin >> c1;
    std::cout << "Enter second complex number:\n";
    std::cin >> c2;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << diff << std::endl;

    return 0;
}