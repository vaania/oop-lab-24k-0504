#include <iostream>
#include <cstring>
using namespace std;

class Device
{

    int deviceID;
    string deviceName;
    bool status;

public:
    virtual void turnON(bool status)
    {
        cout << "The device is turned ON." << endl;
    }
    virtual void turnOFF(bool status)
    {
        cout << "The device is turned OFF." << endl;
    }

    virtual bool getStatus()
    {
        if (status == true)
        {
            return status;
        }
        else
        {
            return status;
        }
    }

    virtual void displayInfo()
    {
        cout << "Device ID: " << deviceID << "| Device Name: " << deviceName << "| Status: " << getStatus() << endl;
    }
};

class Light : public Device
{
    string brightnessLevel;
    string colourMode;

public:
    Light(string bl, string mode) : brightnessLevel(bl), colourMode(mode) {
        cout<<"Light details:"<<endl;
    }
    void displayInfo() override
    {
        cout << "Brightness Level: " << brightnessLevel << " | Colour mode: " << colourMode << endl;
    }
};

class Thermostat : public Device
{
    float temperature;
    string mode;
    float targetTemp;

public:
    Thermostat(float temp, string mode, float target) : temperature(temp), mode(mode), targetTemp(target) {
        cout<<"\nThermostat details:"<<endl;
    }
    bool getStatus() override
    {
        cout << "Current Temperature: " << temperature << " | Mode: " << mode << " | Target Temperature: " << targetTemp << endl;
    }
};

class securityCamera : public Device
{
    string resolution;
    bool recordingStatus;
    bool nightVision;

public:
    securityCamera(string res, bool status, bool vision) : resolution(res), recordingStatus(status), nightVision(vision) {
        cout<<"\nSecurity Camera details:"<<endl;
    }
    void turnON(bool recordingStatus) override
    {

        cout << "Security camera truned ON. Recording started. Recording Status: " << recordingStatus << endl;
    }
};

class smartPlug : public Device
{
    int powerConsumption;
    int timerSetting;

public:
    smartPlug(int power, int timer) : powerConsumption(power), timerSetting(timer) {
        cout<<"\nSmartPlug details:"<<endl;
    }
    void turnOFF(bool status) override
    {
        cout << "SmartPlug turned OFF. Total Power consumption: " << powerConsumption << endl;
    }
};

int main()
{
    Light l1("High", "Blue");
    l1.displayInfo();

    Thermostat t1(36.5, "cooling", 26);
    t1.getStatus();

    securityCamera c1("High", "True", "True");
    c1.turnON("True");

    smartPlug s1(100, 20);
    s1.turnOFF("True");
}