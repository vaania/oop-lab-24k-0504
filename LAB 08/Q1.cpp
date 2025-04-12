#include <iostream>
#include <cmath>
using namespace std;

class Complex;

double magnitude(const Complex &c);

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex operator+(const Complex &other)
    {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex &other)
    {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex &other)
    {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex &other)
    {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex(
            (real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator);
    }

    friend double magnitude(const Complex &c);

    friend ostream &operator<<(ostream &os, const Complex &c);
};

double magnitude(const Complex &c)
{
    return sqrt(c.real * c.real + c.imag * c.imag);
}

ostream &operator<<(ostream &os, const Complex &c)
{
    os << "(" << c.real << (c.imag >= 0 ? " + " : " - ") << abs(c.imag) << "i)";
    return os;
}

int main()
{
    Complex c1(3, 4);
    Complex c2(1, -2);

    cout << "Complex number c1: " << c1 << endl;
    cout << "Complex number c2: " << c2 << endl;

    Complex sum = c1 + c2;
    cout << "c1 + c2 = " << sum << endl;

    Complex diff = c1 - c2;
    cout << "c1 - c2 = " << diff << endl;

    Complex prod = c1 * c2;
    cout << "c1 * c2 = " << prod << endl;

    Complex div = c1 / c2;
    cout << "c1 / c2 = " << div << endl;

    cout << "Magnitude of c1 = " << magnitude(c1) << endl;
    cout << "Magnitude of c2 = " << magnitude(c2) << endl;

    return 0;
}
