#include "iostream"
#include <string>
using namespace std;

class Car
{
    string Brand;
    string Model;
    float rentalPrice;
    bool availabilityStatus;

public:
    Car()
    {
        Brand = "unknown";
        Model = "generic";
        rentalPrice = 0.0;
        availabilityStatus = "true";
    }

    void updateDetail(string brand, string model, float price, bool availablity)
    {
        Brand = brand;
        Model = model;
        rentalPrice = price;
        availabilityStatus = "available";

        if (!availabilityStatus)
        {
            cout << "car is not available" << endl;
        }
        else
        {
            cout << "car is available" << endl;
        }
    }
    void rentcar()
    {
        bool availablity = false;
        cout << "car has been rented" << endl;
    }
};

int main()
{
    Car car1;
    car1.updateDetail("honda", "generic", 4000.0, true);
    car1.rentcar();
    return 0;
}