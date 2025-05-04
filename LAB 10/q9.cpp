#include <iostream>
#include <fstream>
using namespace std;

class FilePositionTracker {
private:
    ifstream file;

public:
    FilePositionTracker(const string& filename) {
        file.open(filename);
    }

    ~FilePositionTracker() {
        if (file.is_open()) {
            file.close();
        }
    }

    void readAndTrack(int bytes) {
        char* buffer = new char[bytes + 1];
        file.read(buffer, bytes);
        buffer[bytes] = '\0';
        cout << "Read: " << buffer << endl;
        cout << "Current position: " << file.tellg() << endl;
        delete[] buffer;
    }
};

int main() {
    ofstream create("large_log.txt");
    create << "This is line 1\nThis is line 2\nThis is line 3";
    create.close();

    FilePositionTracker tracker("large_log.txt");
    tracker.readAndTrack(10);
    tracker.readAndTrack(10);
    return 0;
}