#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <stdexcept>

class Vehicle {
protected:
    std::string id;
    std::string name;
    std::string year;
    std::string certification;

public:
    Vehicle(const std::string& id, const std::string& name, 
            const std::string& year, const std::string& cert);
    virtual ~Vehicle() = default;
    
    int getYearAsInt() const;
    virtual void display() const = 0;
    virtual void processExtraData() const = 0;
};

class AutonomousCar : public Vehicle {
    float softwareVersion;

public:
    AutonomousCar(const std::string& id, const std::string& name, 
                 const std::string& year, const std::string& cert,
                 const std::string& extraData);
    void display() const override;
    void processExtraData() const override;
};

class ElectricVehicle : public Vehicle {
    int batteryCapacity;

public:
    ElectricVehicle(const std::string& id, const std::string& name,
                   const std::string& year, const std::string& cert,
                   const std::string& extraData);
    void display() const override;
    void processExtraData() const override;
};

class HybridTruck : public Vehicle {
    std::string extraData;

public:
    HybridTruck(const std::string& id, const std::string& name,
               const std::string& year, const std::string& cert,
               const std::string& extraData);
    void display() const override;
    void processExtraData() const override;
};

#endif