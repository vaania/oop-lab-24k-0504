#include <iostream>
using namespace std;

int main() {
    int x, y, z;

    cout << "Enter dimensions x: ";
    cin >> x;

    cout << "Enter dimensions y: ";
    cin >> y;

    cout << "Enter dimensions z: ";
    cin >> z;

    int ***arr=new int**[x];

    for (int i = 0; i < y; i++)
    {
        arr[i]=new int*[y];
        for (int j = 0; j < z; j++)
        {
            arr[i][j]=new int[z];
        }
        
    }
    
    cout << "Enter elements: " << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
               
                cout << "Element[" << i+1 << "][" << j+1 << "][" << k+1 << "] = ";
                cin >> arr[i][j][k];
            }
        }
    }
    cout << "\n3D Array:" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
               
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
            
        }

        cout << endl;
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}