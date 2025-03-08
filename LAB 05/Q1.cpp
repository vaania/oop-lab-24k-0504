#include <iostream>
#include <string>
using namespace std;

class Apartment {
private:
    int id;
    string address;
    string name;

public:
    Apartment(int id, string n, string add) {
        this->id = id;
        name = n;
        address = add;
    }

    Apartment(const Apartment &obj, string n) {
        id = obj.id;
        address = obj.address;
        name = n;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Address: " << address << endl;
    }
};

int main() {
    Apartment apt1(1002, "Vaania", "Street 1");
    Apartment apt2(apt1, "Fatima");

    apt1.display();
    apt2.display();

    return 0;
}
