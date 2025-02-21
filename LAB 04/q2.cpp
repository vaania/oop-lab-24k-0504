#include <iostream>
#include <string>
using namespace std;

class Car
{
    string Brand;
    string Model;
    float rentalPrice;
    bool availabilityStatus;

public:
    Car(string br, string m, float p, bool availability)
    {
        Brand = br;
        Model = m;
        rentalPrice = p;
        availabilityStatus = availability;
    }

    void updateDetail(string brand, string model, float price, bool availability)
    {
        Brand = brand;
        Model = model;
        rentalPrice = price;
        availabilityStatus = availability;

        cout << "Car details updated. " << (availabilityStatus ? "Available" : "Not Available") << endl;
    }

    void rentCar()
    {
        if (availabilityStatus)
        {
            availabilityStatus = false;
            cout << "Car has been rented." << endl;
        }
        else
        {
            cout << "Car is not available for rent." << endl;
        }
    }

    float applyDiscount(int days)
    {
        float discount = 0.0;
        if (days > 10)
        {
            discount = 0.10;
        }
        else if (days > 5)
        {
            discount = 0.05;
        }
        float finalPrice = rentalPrice * days * (1 - discount);
        cout << "Total rental price after discount for " << days << " days: $" << finalPrice << endl;
        return finalPrice;
    }
};

int main()
{
    Car myCar("Honda", "Civic", 50.0, true);
    myCar.rentCar();
    myCar.applyDiscount(7);

    return 0;
}
