#include <iostream>
using namespace std;

class MenuItem
{
protected:
    string dishName;
    double price;

public:
    MenuItem(string name, double pr) : dishName(name), price(pr) {}

    virtual void showDetails() const = 0;
    virtual void prepare() const = 0;

    virtual ~MenuItem() {}
};

class Appetizer : public MenuItem
{
public:
    Appetizer(string name, double pr) : MenuItem(name, pr) {}

    void showDetails() const override
    {
        cout << "Appetizer: " << dishName << " | Price: $" << price << "\n";
    }

    void prepare() const override
    {
        cout << "Preparing appetizer: " << dishName << "\n";
        cout << " - Chopping ingredients\n - Light cooking\n - Plating\n\n";
    }
};

class MainCourse : public MenuItem
{
public:
    MainCourse(string name, double pr) : MenuItem(name, pr) {}

    void showDetails() const override
    {
        cout << "Main Course: " << dishName << " | Price: $" << price << "\n";
    }

    void prepare() const override
    {
        cout << "Preparing main course: " << dishName << "\n";
        cout << " - Full meal preparation\n - Grilling/Cooking\n - Garnishing\n\n";
    }
};

int main()
{
    const int SIZE = 2;
    MenuItem *dishes[SIZE];

    dishes[0] = new Appetizer("Spring Rolls", 4.99);
    dishes[1] = new MainCourse("Grilled Chicken", 12.50);

    for (int i = 0; i < SIZE; ++i)
    {
        dishes[i]->showDetails();
        dishes[i]->prepare();
    }

    for (int i = 0; i < SIZE; ++i)
    {
        delete dishes[i];
    }

    return 0;
}
