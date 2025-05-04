#include <iostream>
#include <fstream>
using namespace std;

class RecordReader {
private:
    ifstream file;

public:
    RecordReader(const string& filename) {
        file.open(filename);
    }

    ~RecordReader() {
        if (file.is_open()) {
            file.close();
        }
    }

    string readRecord(int recordNumber) {
        file.seekg((8 + 1) * (recordNumber - 1));
        
        string record;
        getline(file, record);
        return record;
    }
};

int main() {
    ofstream create("data_records.txt");
    create << "Record 1\nRecord 2\nRecord 3\nRecord 4\n";
    create.close();

    RecordReader reader("data_records.txt");
    cout << "Third record: " << reader.readRecord(3) << endl;
    return 0;
}