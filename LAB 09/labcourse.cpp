// LabCourse.cpp
#include <iostream>
#include "labcourse.h"
using namespace std;

LabCourse::LabCourse(string code, int cred) : Course(code, cred) {}

void LabCourse::calculateGrade() {
    cout << "Calculating grade for Lab Course " << courseCode << endl;
}

void LabCourse::displayInfo() {
    cout << "Lab Course: " << courseCode << ", Credits: " << credits << endl;
}
