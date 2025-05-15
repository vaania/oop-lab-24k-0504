#include <iostream>
#include <exception>
using namespace std;

class NegativeStockException : public exception {
};

class OverCapacityException : public exception {
};

template <typename T>
class InventoryItem {
private:
    T stock;
    T maxLimit;

public:
    InventoryItem(T maxLimit) : stock(0), maxLimit(maxLimit) {}

    void setStock(T newStock) {
        if (newStock < 0) {
            throw NegativeStockException();
        }
        if (newStock > maxLimit) {
            throw OverCapacityException();
        }
        stock = newStock;
    }

    T getStock() const {
        return stock;
    }
};

int main() {
    InventoryItem<int> item(100);

    try {
        cout << "Attempting to set stock to -5..." << endl;
        item.setStock(-5);
    } catch (const NegativeStockException& e) {
        cout << "Caught NegativeStockException - what(): " << e.what() << endl;
    }

    try {
        cout << "Attempting to set stock to 120 (max 100)..." << endl;
        item.setStock(120);
    } catch (const OverCapacityException& e) {
        cout << "Caught OverCapacityException - what(): " << e.what() << endl;
    }

    return 0;
}
