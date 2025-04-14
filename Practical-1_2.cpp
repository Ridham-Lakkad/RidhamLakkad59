#include <iostream>
#include <vector>
using namespace std;

struct Product {
    int id;
    string name;
    int quantity;
    float price;
};

class Inventory {
    vector<Product> products;
public:
    void addProduct(int id, string name, int qty, float price) {
        products.push_back({id, name, qty, price});
    }
    void updateQuantity(int id, int qtyChange) {
        for (auto &p : products) {
            if (p.id == id) {
                p.quantity += qtyChange;
                return;
            }
        }
    }
    float totalValue() {
        float total = 0;
        for (auto &p : products) {
            total += p.quantity * p.price;
        }
        return total;
    }
    void displayInventory() {
        for (auto &p : products) {
            cout << "ID: " << p.id << ", Name: " << p.name
                 << ", Qty: " << p.quantity << ", Price: " << p.price << endl;
        }
        cout << "Total inventory value: " << totalValue() << endl;
    }
};

int main() {
    Inventory store;
    store.addProduct(1, "Pen", 100, 5);
    store.addProduct(2, "Notebook", 50, 20);
    store.updateQuantity(1, -10);
    store.displayInventory();

    cout<<"Ridham Lakkad:24CE059"<<endl;
    return 0;
}
