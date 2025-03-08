#include "iostream"
using namespace std;

class Device
{
private:
    int deviceID;
    bool status;

public:
    Device(int id, bool s) : deviceID(id), status(s) {}
    void display()
    {
        cout << "Device ID: " << deviceID << ", Status: " << (status ? "ON" : "OFF") << endl;
    }
};
class Smartphone : public Device
{
private:
    float screensize;

public:
    Smartphone(int id, bool s, float ss) : Device(id, s), screensize(ss) {}
    void display()
    {
        Device::display();
        cout << "Screen Size: " << screensize << " inches" << endl;
    }
};
class Smartwatch : public Device
{
protected:
    bool heartRateMonitor;

public:
    Smartwatch(int id, bool s, bool h) : Device(id, s), heartRateMonitor(h) {}
    void display()
    {
        Device::display();
        cout << "Heart Rate Monitor: " << (heartRateMonitor ? "ON" : "OFF") << endl;
    }
};
class SmartWearable : public Smartphone, public Smartwatch
{
private:
    int stepCounter;

public:
    SmartWearable(int id, bool s, float ss, bool h, int sc) : Smartphone(id, s, ss), Smartwatch(id, s, h), stepCounter(sc) {}
    void display()
    {
        Smartphone::display();
        cout << " Heart Rate Monitor: " << (heartRateMonitor ? "Yes" : "No") << endl;
        cout << "Step Counter: " << stepCounter << endl;
    }
};
int main()
{
    SmartWearable s1(404, false, 8.0, true, 20000);
    s1.display();
    return 0;
}