#include <iostream>
#include <string>
using namespace std;

class Car
{
    string Brand;
    string Model;
    float rentalPrice;
    bool availabilityStatus;
    float totalRevenue;

public:
    Car(string br, string m, float p, bool availability)
    {
        Brand = br;
        Model = m;
        rentalPrice = p;
        availabilityStatus = availability;
    }

    Car(const Car &other)
        : Brand(other.Brand), Model(other.Model), rentalPrice(other.rentalPrice), availabilityStatus(other.availabilityStatus), totalRevenue(other.totalRevenue)
    {
        cout << "Car copy constructor called." << endl;
    }

    ~Car()
    {
        cout << "Car object for " << Brand << " " << Model << " is being deleted." << endl;
    }

    void updateDetail(string brand, string model, float price, bool availability)
    {
        Brand = brand;
        Model = model;
        rentalPrice = price;
        availabilityStatus = availability;

        cout << "Car details updated. " << (availabilityStatus ? "Available" : "Not Available") << endl;
    }

    void rentCar(int days)
    {
        if (availabilityStatus)
        {
            availabilityStatus = false;
            float revenue = rentalPrice * days;
            this->totalRevenue += revenue;
            cout << "Car has been rented for " << days << " days. Revenue generated: $" << revenue << endl;
        }
        else
        {
            cout << "Car is not available for rent." << endl;
        }
    }

    void displayDetails() const
    {
        cout << "Car: " << Brand << " " << Model << "Price: Rs " << rentalPrice << " | "
             << (availabilityStatus ? "Available" : "Not Available") << " Revenue: Rs " << totalRevenue << endl;
    }
};

int main()
{

    Car myCar("Toyota", "Camry", 5600.0, true);
    myCar.displayDetails();

    Car copiedCar = myCar;
    copiedCar.displayDetails();

    myCar.rentCar(7);
    myCar.displayDetails();

    myCar.updateDetail("Honda", "Civic", 7800.0, false);
    myCar.displayDetails();
    copiedCar.displayDetails();

    return 0;
}
