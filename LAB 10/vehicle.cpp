#include "vehicle.h"
#include <iostream>
#include <sstream>

Vehicle::Vehicle(const std::string& id, const std::string& name, 
                const std::string& year, const std::string& cert)
    : id(id), name(name), year(year), certification(cert) {}

int Vehicle::getYearAsInt() const {
    try {
        return std::stoi(year);
    } catch (const std::exception& e) {
        std::cerr << "Error converting year: " << e.what() << std::endl;
        return 0;
    }
}

AutonomousCar::AutonomousCar(const std::string& id, const std::string& name,
                           const std::string& year, const std::string& cert,
                           const std::string& extraData)
    : Vehicle(id, name, year, cert) {
    size_t colonPos = extraData.find(':');
    if (colonPos != std::string::npos) {
        softwareVersion = std::stof(extraData.substr(colonPos + 1));
    }
}

void AutonomousCar::display() const {
    std::cout << "Autonomous Car - ID: " << id << ", Name: " << name 
              << ", Year: " << year << ", Certification: " << certification << std::endl;
}

void AutonomousCar::processExtraData() const {
    std::cout << "Software Version: " << softwareVersion << std::endl;
}

ElectricVehicle::ElectricVehicle(const std::string& id, const std::string& name,
                               const std::string& year, const std::string& cert,
                               const std::string& extraData)
    : Vehicle(id, name, year, cert) {
    size_t colonPos = extraData.find(':');
    if (colonPos != std::string::npos) {
        batteryCapacity = std::stoi(extraData.substr(colonPos + 1));
    }
}

void ElectricVehicle::display() const {
    std::cout << "Electric Vehicle - ID: " << id << ", Name: " << name 
              << ", Year: " << year << ", Certification: " << certification << std::endl;
}

void ElectricVehicle::processExtraData() const {
    std::cout << "Battery Capacity: " << batteryCapacity << " kWh" << std::endl;
}

HybridTruck::HybridTruck(const std::string& id, const std::string& name,
                        const std::string& year, const std::string& cert,
                        const std::string& extraData)
    : Vehicle(id, name, year, cert), extraData(extraData) {}

void HybridTruck::display() const {
    std::cout << "Hybrid Truck - ID: " << id << ", Name: " << name 
              << ", Year: " << year << ", Certification: " << certification << std::endl;
}

void HybridTruck::processExtraData() const {
    std::cout << "Extra Data: " << extraData << std::endl;
}