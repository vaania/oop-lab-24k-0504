#include <iostream>
#include <string>

using namespace std;

class Car
{
private:
    string brand;
    string model;
    int fuelCapacity;
    int currentLevel;
    int fuelUsed;

public:
    Car(string br, string m, int fuel, int level)
        : brand(br), model(m), fuelCapacity(fuel), currentLevel(level), fuelUsed(0) {}

    void driveCar(int distance, int fuelPerKm)
    {
        int fuelRequired = distance * fuelPerKm;
        if (fuelRequired > currentLevel)
        {
            cout << "Not enough fuel to drive this distance!" << endl;
            return;
        }
        currentLevel -= fuelRequired;
        fuelUsed += fuelRequired;
        cout << "Fuel reduced! Current level: " << currentLevel << endl;
    }

    void carDetails()
    {
        cout << "The car is " << brand << " " << model
             << ". Fuel level: " << currentLevel
             << ". Fuel used: " << fuelUsed << endl;
    }

    void refuel(int newFuel)
    {
        if (currentLevel + newFuel > fuelCapacity)
        {
            cout << "Fuel tank full! Cannot exceed capacity of " << fuelCapacity << " liters." << endl;
            currentLevel = fuelCapacity;
        }
        else
        {
            currentLevel += newFuel;
            cout << "Fuel refilled! Current level: " << currentLevel << endl;
        }
    }

    void checkLevel()
    {
        if (currentLevel < 10)
        {
            cout << "Low on fuel! Must be refilled immediately!" << endl;
        }
        else
        {
            cout << "Fuel level: Good." << endl;
        }
    }
};

int main()
{
    Car c1("Toyota", "Corolla", 50, 20);

    c1.carDetails();
    c1.driveCar(5, 2);
    c1.checkLevel();
    c1.refuel(15);
    c1.carDetails();

    return 0;
}
