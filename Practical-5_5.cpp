#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual double Area() const = 0; 
    virtual ~Shape() {}               
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double Area() const override {
        return length * width;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double Area() const override {
        return 3.14159 * radius * radius;
    }
};

int main() {
    vector<Shape*> shapes;

    shapes.push_back(new Rectangle(5.0, 3.0));
    shapes.push_back(new Circle(2.0));
    shapes.push_back(new Rectangle(4.5, 6.0));
    shapes.push_back(new Circle(3.5));

    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << "Shape " << (i + 1) << " Area: " << shapes[i]->Area() << endl;
    }

    for (size_t i = 0; i < shapes.size(); ++i) {
        delete shapes[i];
    }
    shapes.clear();

    cout<<endl;
    cout << "\nRIDHAM LAKKAD : 24CE059" << endl;

    return 0;
}
