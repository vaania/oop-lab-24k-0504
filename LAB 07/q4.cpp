#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string contactNumber;
    string address;
public:
    Person(string n, int a, string c, string addr = "") : name(n), age(a), contactNumber(c), address(addr) {}
   
    virtual void displayInfo() {
        cout << "Name: " << name << "\nAge: " << age << "\nContact: " << contactNumber << "\nAddress: " << address << endl;
    }
   
    virtual void updateInfo(string n, int a, string c, string addr) {
        name = n;
        age = a;
        contactNumber = c;
        address = addr;
    }
};

class Patient : public Person {
    string patientID;
    string medicalHistory;
    string doctorAssigned;
public:
    Patient(string n, int a, string c, string pID, string mH, string dA, string addr = "")
        : Person(n, a, c, addr), patientID(pID), medicalHistory(mH), doctorAssigned(dA) {}
   
        void displayInfo() override {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << "\nMedical History: " << medicalHistory << "\nDoctor Assigned: " << doctorAssigned << endl;
    }
};

class Doctor : public Person {
    string specialization;
    double consultationFee;
    string patientsList[10];
    int patientCount;
public:
    Doctor(string n, int a, string c, string spec, double fee, string addr = "")
        : Person(n, a, c, addr), specialization(spec), consultationFee(fee), patientCount(0) {}
   
        void addPatient(string patientID) {
        if (patientCount < 10) {
            patientsList[patientCount++] = patientID;
        }
    }
   
    void displayInfo() override {
        Person::displayInfo();
        cout << "Specialization: " << specialization << "\nConsultation Fee: " << consultationFee << "\nPatients List: ";
        for (int i = 0; i < patientCount; i++) cout << patientsList[i] << " ";
        cout << endl;
    }
};

class Nurse : public Person {
    string assignedWard;
    string shiftTimings;
public:
    Nurse(string n, int a, string c, string ward, string shift, string addr = "")
        : Person(n, a, c, addr), assignedWard(ward), shiftTimings(shift) {}
   
        void displayInfo() override {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << "\nShift Timings: " << shiftTimings << endl;
    }
};

class Administrator : public Person {
    string department;
    double salary;
public:
    Administrator(string n, int a, string c, string dept, double sal, string addr = "")
        : Person(n, a, c, addr), department(dept), salary(sal) {}
   
        void updateInfo(string n, int a, string c, string addr, string dept, double sal) {
        Person::updateInfo(n, a, c, addr);
        department = dept;
        salary = sal;
    }
   
    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: " << salary << endl;
    }
};

int main() {
    Patient p1("Sadia", 30, "12378509", "P001", "Diabetes", "Dr. Smith");
    Doctor d1("Dr. Sania", 45, "9846522610", "Dermatologist", 500);
    Nurse n1("Dania", 35, "12345678", "Inpatient", "Night");
    Administrator a1("Vaania", 50, "111223344", "HR", 60000);
    
    p1.displayInfo();
    cout << "\n";
    d1.displayInfo();
    cout << "\n";
    n1.displayInfo();
    cout << "\n";
    a1.displayInfo();
    
    return 0;
}
