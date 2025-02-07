#include <iostream>
#include <string>
using namespace std;

void sort(string arr[], int n){
   
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1]){
                string temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
}

int main()
{
    int n;
   
    cout << "Enter the number of strings you want: ";
    cin >> n;
   
    cin.ignore();

    string* arr= new string[n];
    
    for (int i = 0; i < n; i++)
    {
        cout << "Enter string" << i+1 << ": ";
        getline(cin, arr[i]);
    }

    sort(arr,n);

    cout << "Sorted strings:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    
    delete[] arr;
    
    return 0;
}