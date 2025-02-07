#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int;
        cout << "Enter Element " << i + 1 << ": ";
        cin >> *arr[i];
    }
    cout << "Array Elements :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << *arr[i] << " | " ;
    }
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}