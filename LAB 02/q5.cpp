#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the number of integers you want: ";
    cin >> n;
   
    int *ptr = new int[n];
   
    for (int i = 0; i < n; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> *(ptr + i);
    }
   
    cout << "Entered array:" << endl;
    
    for (int i = 0; i < n; i++)
    {
        cout << *(ptr + i) << " ";
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += *(ptr + i);
    }
   
    cout << "\n Sum of array of integers:" << sum << endl;
   
    delete[] ptr;
   
    return 0;
}