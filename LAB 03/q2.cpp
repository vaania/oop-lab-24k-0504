#include <iostream>
#include <string>

using namespace std;

class FitnessTracker
{
private:
    string userName;
    int dailyStepGoal;
    int stepsTaken;
    double caloriesBurned;

public:
    FitnessTracker(string name, int goal)
    {
        userName = name;
        dailyStepGoal = goal;
        stepsTaken = 0;
        caloriesBurned = 0.0;
    }

    void logSteps(int steps)
    {
        if (steps > 0)
        {
            stepsTaken += steps;
            caloriesBurned += steps * 0.04;
        }
    }

    bool hasMetGoal()
    {
        return stepsTaken >= dailyStepGoal;
    }

    void displayProgress()
    {
        cout << "User: " << userName << endl;
        cout << "Daily Step Goal: " << dailyStepGoal << endl;
        cout << "Steps Taken: " << stepsTaken << endl;
        cout << "Calories Burned: " << caloriesBurned << " kcal" << endl;
        cout << (hasMetGoal() ? "Goal Achieved! Keep it up!" : "Keep going, you can do it!") << endl;
    }
};

int main()
{
    FitnessTracker laiba("Laiba", 10000);

    laiba.logSteps(5000);
    laiba.displayProgress();

    laiba.logSteps(6000);
    laiba.displayProgress();

    return 0;
}
