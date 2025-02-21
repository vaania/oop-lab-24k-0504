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
    string registrationNumber; 

public:
   
    Car(string regNum, string br, string m, float p, bool availability)
        : registrationNumber(regNum), Brand(br), Model(m), rentalPrice(p), availabilityStatus(availability), totalRevenue(0.0) {}

    
    Car(const Car &other)
        : registrationNumber(other.registrationNumber), Brand(other.Brand), Model(other.Model), rentalPrice(other.rentalPrice), availabilityStatus(other.availabilityStatus), totalRevenue(other.totalRevenue)
    {
        cout << "Car copy constructor called." << endl;
    }

    
    ~Car()
    {
        cout << "Car object for " << Brand << " " << Model << " (" << registrationNumber << ") is being deleted." << endl;
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
            cout << "Car (" << registrationNumber << ") has been rented for " << days << " days. Revenue generated: Rs " << revenue << endl;
        }
        else
        {
            cout << "Car (" << registrationNumber << ") is not available for rent." << endl;
        }
    }

    
    
    void displayDetails() const
    {
        cout << "Car Registration: " << registrationNumber << " Brand: " << Brand << " " << Model << " Price: Rs " << rentalPrice << " | "
             << (availabilityStatus ? "Available" : "Not Available") << " Total Revenue: Rs" << totalRevenue << endl;
    }
};

int main()
{
    
    Car myCar("ABC123", "Toyota", "Camry", 5700.0, true);
    myCar.displayDetails();
    Car copiedCar = myCar;
    copiedCar.displayDetails();
    myCar.rentCar(7);
    myCar.displayDetails();
    myCar.updateDetail("Honda", "Civic", 8500.0, false);
    myCar.displayDetails();
    copiedCar.displayDetails(); 

    return 0;
}
