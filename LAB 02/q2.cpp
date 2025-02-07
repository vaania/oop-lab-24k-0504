#include <iostream>
using namespace std;

int main(){
    int rows, cols;

    cout << "Enter number of rows of matrix 1 and matrix 2: ";
    cin >> rows;

    cout << "Enter number of columns of matrix 1 and matrix 2: ";
    cin >> cols;

    int **ptr1= new int *[rows];
 
    for (int i = 0; i < rows; i++)
    {
        ptr1[i]= new int [cols];
    }
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element for matrix 1, Row " << i+1 << " Col " << j+1 << ": ";
            cin >> *(*(ptr1+i)+j);
        }
        
    }
    
    int **ptr2= new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        ptr2[i] = new int [cols];
    }
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element for Matrix 2, Row " << i+1 << " Col " << j+1 << ": ";
            cin >> *(*(ptr2+i)+j);
        }
        
    }
    
    int **ptr3= new int *[rows];
    
    for (int i = 0; i < rows; i++)
    {
        ptr3[i]= new int [cols];
    }
    
    int **ptr4= new int *[rows];
    
    for (int i = 0; i < rows; i++)
    {
        ptr4[i] = new int [cols];
    }
    cout << "Addition of matrices" << endl;
   
    for (int i = 0; i < rows; i++)
    {
        cout << "|";
        for (int j = 0; j < cols; j++)
        {
            ptr3[i][j] = ptr1[i][j] + ptr2[i][j];
            cout << ptr3[i][j] << " | ";
        }
        cout << endl;
    }
    cout << "Subtraction of matrices" << endl;
    
    for (int i = 0; i < rows; i++)
    {
        cout << "|";
        for (int j = 0; j < cols; j++)
        {
            ptr4[i][j] = ptr1[i][j] - ptr2[i][j];
            cout << ptr4[i][j] << " | ";
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i++)
    {
        delete[] ptr1[i];
        delete[] ptr2[i];
        delete[] ptr3[i];
        delete[] ptr4[i];
    }
 
    delete[] ptr1;
    delete[] ptr2;
    delete[] ptr3;
    delete[] ptr4;
 
    return 0;
}