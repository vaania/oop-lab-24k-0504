#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int ID;
    float marks[3];
};

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    cin.ignore();
    Student* records = new Student[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Name: ";

        getline(cin, records[i].name);

        cout << "Roll Number: ";
        cin >> records[i].ID;
        
        for (int j = 0; j < 3; j++) {
            cout << "Enter marks in subject " << j+1 << " :";
            cin >> records[i].marks[j];
        }
        cin.ignore();
    }

    for (int i = 0; i < n; i++) {
        float avg = (records[i].marks[0] + records[i].marks[1] + records[i].marks[2]) / 3.0;
        cout << "Name: " << records[i].name << ", Average Marks: " << avg << endl;
    }

    delete[] records;

    return 0;
}