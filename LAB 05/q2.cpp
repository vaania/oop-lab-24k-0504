#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    int id;
    string name;
    int* scores;
    int numScores;

public:
    Student(int id, string n, int* scoreArray, int count) : id(id), name(n), numScores(count) {
        scores = new int[numScores];
        for (int i = 0; i < numScores; i++) {
            scores[i] = scoreArray[i];
        }
    }

    Student(const Student& obj) : id(obj.id), name(obj.name), numScores(obj.numScores) {
        scores = new int[numScores];
        for (int i = 0; i < numScores; i++) {
            scores[i] = obj.scores[i];
        }
    }

    ~Student() {
        delete[] scores;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Scores: ";
        for (int i = 0; i < numScores; i++) {
            cout << scores[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int scores1[] = {89, 92, 76};
    Student s1(44, "Vaania", scores1, 3);

    int scores2[] = {87, 85, 90};
    Student s2(55, "Iqra", scores2, 3);

    Student s3 = s1;

    cout << "Original Student 1 Details:" << endl;
    s1.display();

    cout << "\nOriginal Student 2 Details:" << endl;
    s2.display();

    cout << "\nCopied Student Details:" << endl;
    s3.display();

    return 0;
}
