#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class InventoryItem {
private:
    int itemID;
    char itemName[20];

public:
    InventoryItem(int id = 0, const char* name = "") : itemID(id) {
        strncpy(itemName, name, 19);
        itemName[19] = '\0';
    }

    void saveToFile(const string& filename) {
        ofstream outFile(filename, ios::binary);
        outFile.write(reinterpret_cast<char*>(this), sizeof(*this));
        outFile.close();
    }

    static InventoryItem loadFromFile(const string& filename) {
        InventoryItem item;
        ifstream inFile(filename, ios::binary);
        inFile.read(reinterpret_cast<char*>(&item), sizeof(item));
        inFile.close();
        return item;
    }

    void display() const {
        cout << "ID: " << itemID << ", Name: " << itemName << endl;
    }
};

int main() {
    InventoryItem item1(123, "Laptop");
    item1.saveToFile("inventory.dat");

    InventoryItem item2 = InventoryItem::loadFromFile("inventory.dat");
    item2.display();

    return 0;
}