#include <iostream>
#include "lecCourse.h"
using namespace std;

LectureCourse::LectureCourse(string code, int cred) : Course(code, cred) {}

void LectureCourse::calculateGrade() {
    cout << "Calculating grade for Lecture Course " << courseCode << endl;
}

void LectureCourse::displayInfo() {
    cout << "Lecture Course: " << courseCode << ", Credits: " << credits << endl;
}
