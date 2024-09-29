#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    int id;
    float price;
    int quantity;
    int maxQuantity;

public:

    Product(string name, int id, float price, int quantity, int maxQuantity) {
        this->name = name;
        this->id = id;
        this->price = price;
        this->quantity = quantity;
        this->maxQuantity = maxQuantity;
    }

    void addToInventory(int addedQuantity) {
        if (quantity + addedQuantity <= maxQuantity) {
            quantity += addedQuantity;
            cout << addedQuantity << " units added to inventory.\n";
        } else {
            cout << "Can not add " << addedQuantity << " units. exceeds maximum capacity.\n";
        }
    }

    bool isAvailable() {
        return quantity > 0;
    }




    void purchase(int purchasedQuantity) {
        if (isAvailable()) {
            if (quantity >= purchasedQuantity) {
                quantity -= purchasedQuantity;
                cout << purchasedQuantity << " units purchased.\n";
            } else {
                cout << "Only " << quantity << " units available. Purchase not possible.\n";
            }
        } else {
            cout << "Product out of stock.\n";
        }
    }

    void updatePrice(int discountPercent) {
        price = price * (1 - discountPercent / 100.0);
        cout << "Price updated with " << discountPercent << "% discount.\n";
    }


    void displayInventoryValue() {
        float inventoryValue = price * quantity;
        cout << "Total inventory value of " << name << ": $" << inventoryValue << endl;
    }

    void displayDetails() {
        cout << "Product ID: " << id << "\nName: " << name << "\nPrice: $" << price
             << "\nQuantity: " << quantity << "\nAvailability: " << (isAvailable() ? "In Stock" : "Out of Stock") << endl;
    }


    static void displayTotalInventoryValue(Product products[], int size) {
        float totalValue = 0;
        for (int i = 0; i < size; i++) {
            totalValue += products[i].price * products[i].quantity;
        }
        cout << "Total inventory value of all products: $" << totalValue << endl;
    }
};

int main() {

    Product product1("Laptop", 101, 1000, 10, 50);
    product1.addToInventory(5);
    product1.purchase(3);
    product1.updatePrice(5);
    product1.displayInventoryValue();
    product1.displayDetails();

    Product product2("Smartphone", 102, 500, 20, 40);
    Product product3("Tablet", 103, 300, 15, 30);

    Product products[] = { product1, product2, product3 };
    Product::displayTotalInventoryValue(products, 3);

    return 0;
}

