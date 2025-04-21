#include <iostream>
using namespace std;

class WeatherSensor {
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
};

class Thermometer : public WeatherSensor {
public:
    void readData() override {
        cout << "Reading temperature data." << endl;
    }
    void displayReport() override {
        cout << "Displaying temperature report." << endl;
    }
};

class Barometer : public WeatherSensor {
public:
    void readData() override {
        cout << "Reading pressure data." << endl;
    }
    void displayReport() override {
        cout << "Displaying pressure report." << endl;
    }
};

int main() {
    WeatherSensor* sensors[2];
    sensors[0] = new Thermometer();
    sensors[1] = new Barometer();

    for (int i = 0; i < 2; ++i) {
        sensors[i]->readData();
        sensors[i]->displayReport();
        delete sensors[i];
    }

    return 0;
}