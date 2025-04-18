#include <iostream>
using namespace std;

class Patient {
protected:
    string name;
    string id;

public:
    Patient(string n, string i) : name(n), id(i) {}

    virtual void displayTreatment() const = 0;
    virtual double calculateCost() const = 0;

    virtual ~Patient() {}
};

class InPatient : public Patient {
public:
    InPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() const override {
        cout << "In-Patient Treatment Plan for " << name << " (ID: " << id << ")\n";
        cout << " - Room admission\n - Daily medical care\n - Diagnostic tests\n";
    }

    double calculateCost() const override {
        double roomCharges = 2000;
        double careCharges = 1500;
        double testCharges = 1000;
        return roomCharges + careCharges + testCharges;
    }
};

class OutPatient : public Patient {
public:
    OutPatient(string n, string i) : Patient(n, i) {}

    void displayTreatment() const override {
        cout << "Out-Patient Treatment Plan for " << name << " (ID: " << id << ")\n";
        cout << " - Consultation\n - Prescribed medication\n";
    }

    double calculateCost() const override {
        double consultationFee = 500;
        double medicineCost = 300;
        return consultationFee + medicineCost;
    }
};


int main() {
    const int SIZE = 2;
    Patient* patients[SIZE];  

    patients[0] = new InPatient("John Doe", "IP1001");
    patients[1] = new OutPatient("Jane Smith", "OP2001");


    for (int i = 0; i < SIZE; ++i) {
        patients[i]->displayTreatment();
        cout << "Total Cost: $" << patients[i]->calculateCost() << "\n\n";
    }

    for (int i = 0; i < SIZE; ++i) {
        delete patients[i];
    }

    return 0;
}
