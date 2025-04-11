#include <iostream>
using namespace std;

class Matrix2x2;

class MatrixHelper {
public:
    void updateElement(Matrix2x2& matrix, int row, int col, int value);
};

class Matrix2x2 {
private:
    int m[2][2];

public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0) {
        m[0][0] = a;
        m[0][1] = b;
        m[1][0] = c;
        m[1][1] = d;
    }

    // Matrix Addition
    Matrix2x2 operator+(const Matrix2x2& other) {
        return Matrix2x2(
            m[0][0] + other.m[0][0], m[0][1] + other.m[0][1],
            m[1][0] + other.m[1][0], m[1][1] + other.m[1][1]
        );
    }

    // Matrix Subtraction
    Matrix2x2 operator-(const Matrix2x2& other) {
        return Matrix2x2(
            m[0][0] - other.m[0][0], m[0][1] - other.m[0][1],
            m[1][0] - other.m[1][0], m[1][1] - other.m[1][1]
        );
    }

    // Matrix Multiplication
    Matrix2x2 operator*(const Matrix2x2& other) {
        return Matrix2x2(
            m[0][0]*other.m[0][0] + m[0][1]*other.m[1][0],
            m[0][0]*other.m[0][1] + m[0][1]*other.m[1][1],
            m[1][0]*other.m[0][0] + m[1][1]*other.m[1][0],
            m[1][0]*other.m[0][1] + m[1][1]*other.m[1][1]
        );
    }

    // Friend function to calculate determinant
    friend int determinant(const Matrix2x2& matrix);

    // Friend class
    friend class MatrixHelper;

    // Overload << to print the matrix
    friend ostream& operator<<(ostream& os, const Matrix2x2& matrix);
};

// Determinant function
int determinant(const Matrix2x2& matrix) {
    return (matrix.m[0][0] * matrix.m[1][1]) - (matrix.m[0][1] * matrix.m[1][0]);
}

// Print matrix
ostream& operator<<(ostream& os, const Matrix2x2& matrix) {
    os << "[ " << matrix.m[0][0] << " " << matrix.m[0][1] << " ]\n";
    os << "[ " << matrix.m[1][0] << " " << matrix.m[1][1] << " ]\n";
    return os;
}

// MatrixHelper method
void MatrixHelper::updateElement(Matrix2x2& matrix, int row, int col, int value) {
    if(row >= 0 && row < 2 && col >= 0 && col < 2) {
        matrix.m[row][col] = value;
    }
}

int main() {
    Matrix2x2 A(1, 2, 3, 4);
    Matrix2x2 B(5, 6, 7, 8);

    cout << "Matrix A:\n" << A;
    cout << "Matrix B:\n" << B;

    Matrix2x2 sum = A + B;
    cout << "A + B:\n" << sum;

    Matrix2x2 diff = A - B;
    cout << "A - B:\n" << diff;

    Matrix2x2 prod = A * B;
    cout << "A * B:\n" << prod;

    cout << "Determinant of A: " << determinant(A) << endl;

    MatrixHelper helper;
    helper.updateElement(A, 0, 1, 10);
    cout << "Matrix A after updating element (0,1) to 10:\n" << A;

    return 0;
}
