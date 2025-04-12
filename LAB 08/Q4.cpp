#include <iostream>
#include <string>
using namespace std;

class Car;

void comparePrice(const Car &car1, const Car &car2);

class InventoryManager
{
public:
    void updatePrice(Car &car, double newPrice);
    void displayCar(const Car &car);
};

class Car
{
private:
    string model;
    double price;

public:
    Car(string m, double p) : model(m), price(p) {}

    friend class InventoryManager;

    friend void comparePrice(const Car &car1, const Car &car2);
};

void InventoryManager::updatePrice(Car &car, double newPrice)
{
    if (newPrice >= 0)
    {
        car.price = newPrice;
        cout << "Updated price of " << car.model << " to $" << car.price << endl;
    }
    else
    {
        cout << "Invalid price. Cannot update.\n";
    }
}

void InventoryManager::displayCar(const Car &car)
{
    cout << "Model: " << car.model << ", Price: $" << car.price << endl;
}

void comparePrice(const Car &car1, const Car &car2)
{
    cout << "Comparing prices:\n";
    if (car1.price > car2.price)
    {
        cout << car1.model << " is more expensive.\n";
    }
    else if (car1.price < car2.price)
    {
        cout << car2.model << " is more expensive.\n";
    }
    else
    {
        cout << "Both cars are priced equally.\n";
    }
}

int main()
{
    Car car1("Toyota", 25000);
    Car car2("Honda", 24000);

    InventoryManager manager;

    cout << "Initial Car Details:\n";
    manager.displayCar(car1);
    manager.displayCar(car2);

    cout << "\nUpdating Prices:\n";
    manager.updatePrice(car2, 26000);

    cout << "\nUpdated Car Details:\n";
    manager.displayCar(car1);
    manager.displayCar(car2);

    cout << "\nPrice Comparison:\n";
    comparePrice(car1, car2);

    return 0;
}
