#ifndef VEHICLE_PARSER_H
#define VEHICLE_PARSER_H

#include <string>
#include <fstream>
#include "vehicle.h"

class VehicleParser {
public:
    static Vehicle* parseLine(const std::string& line);
    static void processFile(const std::string& filename);
};

#endif