#include "vehicleparse.h"
#include <sstream>
#include <iostream>

Vehicle* VehicleParser::parseLine(const std::string& line) {
    std::istringstream iss(line);
    std::string type, id, name, year, extraData, certification;
    
    std::getline(iss, type, ',');
    std::getline(iss, id, ',');
    std::getline(iss, name, ',');
    std::getline(iss, year, ',');
    std::getline(iss, extraData, ',');
    std::getline(iss, certification);

    if (type == "AutonomousCar") {
        return new AutonomousCar(id, name, year, certification, extraData);
    } else if (type == "ElectricVehicle") {
        return new ElectricVehicle(id, name, year, certification, extraData);
    } else if (type == "HybridTruck") {
        return new HybridTruck(id, name, year, certification, extraData);
    }
    
    return nullptr;
}

void VehicleParser::processFile(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty() || line[0] == '#') continue;
        
        Vehicle* vehicle = parseLine(line);
        if (vehicle) {
            vehicle->display();
            std::cout << "Year as integer: " << vehicle->getYearAsInt() << std::endl;
            vehicle->processExtraData();
            std::cout << "---------------------" << std::endl;
            delete vehicle;
        }
    }

    inputFile.close();
}