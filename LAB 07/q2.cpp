#include "iostream"
using namespace std;

class Product
{
public:
    int productID;
    string productName;
    double price;
    int quantity;
    Product(int id, string name, double p, int q) : productID(id), productName(name), price(p), quantity(q) {}
    virtual void applyDiscount()
    {
        price *= 0.9;
    }
    virtual double TotalPrice(int quantity)
    {
        return price * quantity;
    }
    virtual void displayProductInfo()
    {
        cout << "\nProduct ID: " << productID << "| Name: " << productName << "| Price: Rs" << price << "| Quantity: " << quantity << endl;
    }
};

class Electronics : public Product
{
public:
    int warrantyPeriod;
    string brand;
    Electronics(int id, string name, double p, int q, int w, string b) : Product(id, name, p, q), warrantyPeriod(w), brand(b) {}
    void displayProductInfo() override
    {
        Product::displayProductInfo();
        cout << "\nWarranty Period: " << warrantyPeriod << " years | Brand: " << brand << endl;
    }
};

class Clothing : public Product
{
public:
    string size;
    string color;
    string fabricMaterial;
    Clothing(int id, string name, double p, int q, string s, string c, string f) : Product(id, name, p, q), size(s), color(c), fabricMaterial(f) {}
    void applyDiscount() override
    {
        price *= 0.8;
    }
};

class FoodItem : public Product
{
public:
    string expiryDate;
    int calories;
    FoodItem(int id, string name, double p, int q, string d, int c) : Product(id, name, p, q), expiryDate(d), calories(c) {}
    double TotalPrice(int quantity) override
    {
        price = price * quantity;
        if (quantity >= 5)
        {
            price *= 0.85;
        }
        return price;
    }
};
class Book : public Product
{
public:
    string author;
    string genre;
    Book(int id, string name, double p, int q, string a, string g) : Product(id, name, p, q), author(a), genre(g) {}
    void displayProductInfo() override
    {
        Product::displayProductInfo();
        cout << "\nAuthor: " << author << "| Genre: " << genre << endl;
    }
};

int main()
{
    Electronics phone(201, "Smartphone", 800.0, 5, 1, "Samsung");
    Clothing jeans(202, "Denim Jeans", 50.0, 40, "M", "Blue", "Denim");
    FoodItem burger(203, "Cheeseburger", 8.0, 25, "2025-12-01", 500);
    Book novel(204, "1984", 20.0, 15, "George Orwell", "Dystopian");

    jeans.applyDiscount();
    phone.applyDiscount();
    novel.TotalPrice(7);

    cout << "\n--- Product Details ---\n";
    phone.displayProductInfo();
    jeans.displayProductInfo();
    burger.TotalPrice(3);
    burger.displayProductInfo();
    novel.displayProductInfo();
    return 0;
}