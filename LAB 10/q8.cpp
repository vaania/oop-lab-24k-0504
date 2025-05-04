#include <iostream>
#include <fstream>
using namespace std;

class ConfigManager {
private:
    string filename;

public:
    ConfigManager(const string& fn) : filename(fn) {}

    void initialize() {
        ofstream file(filename);
        file << "AAAAABBBBBCCCCC";
        file.close();
    }

    void updateConfig(int position, const string& newValue) {
        fstream file(filename, ios::in | ios::out);
        file.seekp(position);
        file << newValue;
        file.close();
    }

    void display() {
        ifstream file(filename);
        string content;
        getline(file, content);
        cout << "Current config: " << content << endl;
        file.close();
    }
};

int main() {
    ConfigManager config("config.txt");
    config.initialize();
    config.updateConfig(5, "XXXXX");
    config.display();
    return 0;
}