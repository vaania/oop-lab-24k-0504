#include "iostream"
using namespace std;

class Vehicle
{
protected:
    string brand;
    int speed;

public:
    Vehicle(string b, int s) : brand(b), speed(s) {}
    void display()
    {
        cout << "Brand: " << brand << ", Speed: " << speed << endl;
    }
};
class Car : public Vehicle
{
protected:
    int seats;

public:
    Car(string b, int s, int seats) : Vehicle(b, s), seats(seats) {}
    void display()
    {
        Vehicle::display();
        cout << "Seats: " << seats << endl;
    }
};
class Electriccar : public Car
{
protected:
    int batterylife;

public:
    Electriccar(string b, int s, int seats, int bl) : Car(b, s, seats), batterylife(bl) {}
    void display()
    {
        Car::display();
        cout << "Battery Life: " << batterylife << " hours" << endl;
    }
};

int main()
{
    Electriccar c1("Toyota", 50, 5, 20);
    c1.display();
    return 0;
}