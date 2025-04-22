#include <iostream>
#include "lecCourse.h"
#include "labCourse.h"

int main() {
    Course* courses[2];
    courses[0] = new LectureCourse("CS101", 3);
    courses[1] = new LabCourse("CS102L", 1);

    for (int i = 0; i < 2; ++i) {
        courses[i]->displayInfo();
        courses[i]->calculateGrade();
        delete courses[i];
    }

    return 0;
}
