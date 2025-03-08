#include "iostream"
#include <cstring>
using namespace std;

class Product
{
private:
    int ID, quantity;
    string name;

public:
    Product() : ID(0), name(""), quantity(0) {}
    Product(int id, string n, int q) : ID(id), name(n), quantity(q) {}
    string getName()
    {
        return name;
    }
    int getID()
    {
        return ID;
    }
    void display()
    {
        cout << "Product ID:" << ID << " \nProduct name:" << name << "\nQuantity: " << quantity << endl;
    }
};
class Warehouse
{
private:
    Product product[15];
    int count;

public:
    Warehouse() : count(0) {}
    void addProduct(int id, string name, int quantity)
    {
        if (count < 15)
        {
            product[count++] = Product(id, name, quantity);
        }
        else
        {
            cout << "Warehouse inventory is full!" << endl;
        }
    }
    void sortProducts()
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - i - 1; j++)
            {
                if (product[j].getName() > product[j + 1].getName())
                {
                    swap(product[j], product[j + 1]);
                }
            }
        }
    }
    void searchProduct(int id)
    {
        for (int i = 0; i < count; i++)
        {
            if (product[i].getID() == id)
            {
                cout << "Product Found: " << endl;
                product[i].display();
                return;
            }
        }
        cout << "Product with ID " << id << " not found!" << endl;
    }
    void display()
    {
        cout << "Warehouse Inventory:" << endl;
        for (int i = 0; i < count; i++)
        {
            product[i].display();
        }
    }
};

int main()
{
    Warehouse w;
    w.addProduct(201, "Airbuds", 45);
    w.addProduct(202, "Laptop", 24);
    w.addProduct(203, "Powerbank", 70);
    w.addProduct(204, "Blutooth Headphones", 80);
    w.sortProducts();
    w.display();
    int searchID;
    cout << "Enter Product ID to search: ";
    cin >> searchID;
    w.searchProduct(searchID);
    return 0;
}