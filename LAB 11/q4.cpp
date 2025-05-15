#include <iostream>
#include <exception>
#include <string>
using namespace std;

class DatabaseException : public exception {
public:
    const char* what() const noexcept override {
        return "A database error occurred.";
    }
};

class ConnectionFailedException : public DatabaseException {
};

class QueryTimeoutException : public DatabaseException {
};

template <typename T>
class DatabaseConnector {
private:
    string dbName;

public:
    DatabaseConnector(const string& db) : dbName(db) {}

    void connect() {
        if (dbName == "invalid_db") {
            throw ConnectionFailedException();
        } else if (dbName == "slow_db") {
            throw QueryTimeoutException();
        } else {
            cout << "Connected to " << dbName << " successfully." << endl;
        }
    }
};

int main() {
    try {
        cout << "Attempting to connect to invalid_db..." << endl;
        DatabaseConnector<int> db1("invalid_db");
        db1.connect();
    } catch (const ConnectionFailedException& e) {
        cout << "Caught ConnectionFailedException - what(): " << e.what() << endl;
    }

    try {
        cout << "Attempting to connect to slow_db..." << endl;
        DatabaseConnector<double> db2("slow_db");
        db2.connect();
    } catch (const DatabaseException& e) {
        cout << "Caught a general DatabaseException - what(): " << e.what() << endl;
    }

    return 0;
}
