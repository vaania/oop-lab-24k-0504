#include <iostream>
#include <fstream>
using namespace std;

class SensorLogger {
private:
    ofstream logFile;

public:
    SensorLogger(const string& filename) {
        logFile.open(filename);
    }

    ~SensorLogger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    void log(const string& message) {
        logFile << message << endl;
        cout << "Current position: " << logFile.tellp() << endl;
    }
};

int main() {
    SensorLogger logger("sensor_log.txt");
    logger.log("Temperature: 25.5 C");
    logger.log("Humidity: 50%");
    return 0;
}