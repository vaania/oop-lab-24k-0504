#include "iostream"
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
    void display()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
class Teacher : public Person
{
private:
    string subject;

public:
    Teacher(string n, int a, string sub) : Person(n, a), subject(sub) {}
    void display()
    {
        Person::display();
        cout << "Subject: " << subject << endl;
    }
};
class Researcher : public Person
{
private:
    string researchArea;

public:
    Researcher(string n, int a, string area) : Person(n, a), researchArea(area) {}
    void display()
    {
        cout << "Research Area: " << researchArea << endl;
    }
};
class Professor : public Teacher, public Researcher
{
private:
    int publications;

public:
    Professor(string n, int a, string sub, string area, int pubs) : Teacher(n, a, sub), Researcher(n, a, area), publications(pubs) {}
    void display()
    {
        Teacher::display();
        Researcher::display();
        cout << "Publications: " << publications << endl;
    }
};
int main()
{
    Professor p("Talha Shahid", 45, "CS", "OOP", 10);
    p.display();
    return 0;
}