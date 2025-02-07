#include <iostream>
using namespace std;

int main()
{
    int rows, cols, rows2, cols2;
    cout << "Enter number of rows for Matrix 1: ";
    cin >> rows;

    cout << "Enter number of columns for Matrix 1: ";
    cin >> cols;

    cout << "Enter number of rows for Matrix 2: ";
    cin >> rows2;

    cout << "Enter number of columns for Matrix 2: ";
    cin >> cols2;

    if (cols != rows2)
    {
        cout << "Multiplication not possible!" << endl;
        return 1;
    }

    int **ptr1 = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        ptr1[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element for Matrix 1, Row " << i + 1 << " Col " << j + 1 << ": ";
            cin >> *(*(ptr1 + i) + j);
        }
    }
    int **ptr2 = new int *[rows2];
    for (int i = 0; i < rows2; i++)
    {
        ptr2[i] = new int[cols2];
    }

    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            cout << "Enter element for Matrix 2, Row " << i + 1 << " Col " << j + 1 << ": ";
            cin >> *(*(ptr2 + i) + j);
        }
    }
    int **ptr3 = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        ptr3[i] = new int[cols2];
    }

    cout << "Multiplication of matrices" << endl;
    for (int i = 0; i < rows; i++)
    {
        cout << "|";
        for (int j = 0; j < cols2; j++)
        {
            ptr3[i][j] = 0;
            for (int k = 0; k < cols; k++)
            {
                ptr3[i][j] += ptr1[i][k] * ptr2[k][j];
            }
            cout << ptr3[i][j] << " | ";
        }
        cout << endl;
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] ptr1[i];
        delete[] ptr3[i];
    }
    for (int i = 0; i < rows2; i++)
    {
        delete[] ptr2[i];
    }
    delete[] ptr1;
    delete[] ptr2;
    delete[] ptr3;

    return 0;
}

