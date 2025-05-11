#include <iostream>
#include <stdexcept>
#include <sstream>
using namespace std;

// Custom exception class
class DimensionMismatchException : public exception {
private:
    string message;

public:
    DimensionMismatchException(int r1, int c1, int r2, int c2) {
        ostringstream oss;
        oss << "DimensionMismatchException - Matrices must have same dimensions ("
            << r1 << "x" << c1 << " vs " << r2 << "x" << c2 << ")!";
        message = oss.str();
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Template matrix class
template <typename T>
class Matrix {
private:
    T** data;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i)
            data[i] = new T[cols]{};
    }

    // Copy constructor
    Matrix(const Matrix<T>& other) : rows(other.rows), cols(other.cols) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }

    void set(int r, int c, T value) {
        data[r][c] = value;
    }

    T get(int r, int c) const {
        return data[r][c];
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    // Matrix addition
    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.set(i, j, data[i][j] + other.get(i, j));

        return result;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

// Demonstration
int main() {
    try {
        Matrix<int> A(2, 2);
        A.set(0, 0, 1);
        A.set(0, 1, 2);
        A.set(1, 0, 3);
        A.set(1, 1, 4);

        Matrix<int> B(3, 3); // Incompatible dimensions

        Matrix<int> C = A + B; // Should throw exception
    } catch (const exception& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}
