#include <cmath>
const double PI = 3.141592653589793; 
#include "Triangle.h"
#include <iostream>
#include <sstream>

using namespace std;

int Triangle::count = 0;
int Triangle::Triad::count = 0;

Triangle::Triad::Triad() : a(0), b(0), c(0) { count++; }
Triangle::Triad::Triad(int a, int b, int c) : a(a), b(b), c(c) { count++; }
Triangle::Triad::Triad(const Triad& other) : a(other.a), b(other.b), c(other.c) { count++; }
Triangle::Triad::~Triad() { count--; }

int Triangle::Triad::getA() const { return a; }
int Triangle::Triad::getB() const { return b; }
int Triangle::Triad::getC() const { return c; }

void Triangle::Triad::setA(int value) { a = value; }
void Triangle::Triad::setB(int value) { b = value; }
void Triangle::Triad::setC(int value) { c = value; }

Triangle::Triad& Triangle::Triad::operator=(const Triad& other) {
    if (this != &other) {
        a = other.a;
        b = other.b;
        c = other.c;
    }
    return *this;
}

Triangle::Triad& Triangle::Triad::operator++() {
    ++a; ++b; ++c;
    return *this;
}

Triangle::Triad Triangle::Triad::operator++(int) {
    Triad temp = *this;
    ++(*this);
    return temp;
}

Triangle::Triad& Triangle::Triad::operator--() {
    --a; --b; --c;
    return *this;
}

Triangle::Triad Triangle::Triad::operator--(int) {
    Triad temp = *this;
    --(*this);
    return temp;
}

double Triangle::getArea() const {
    double a = sides.getA();
    double b = sides.getB();
    double c = sides.getC();
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void Triangle::getAngles(double& A, double& B, double& C) const {
    double a = sides.getA();
    double b = sides.getB();
    double c = sides.getC();

    double cosA = (b * b + c * c - a * a) / (2 * b * c);
    double cosB = (a * a + c * c - b * b) / (2 * a * c);
    double cosC = (a * a + b * b - c * c) / (2 * a * b);

    A = acos(cosA) * 180 / PI;
    B = acos(cosB) * 180 / PI;
    C = acos(cosC) * 180 / PI;
}

int Triangle::Triad::Sum() const {
    return a + b + c;
}

string Triangle::Triad::toString() const {
    stringstream ss;
    ss << "Triad(" << a << ", " << b << ", " << c << ")";
    return ss.str();
}

int Triangle::Triad::getCount() {
    return count;
}

Triangle::Triangle() : sides() { count++; }
Triangle::Triangle(int a, int b, int c) : sides(a, b, c) { count++; }
Triangle::Triangle(const Triangle& other) : sides(other.sides) { count++; }
Triangle::~Triangle() { count--; }

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        sides = other.sides;
    }
    return *this;
}

void Triangle::Init(int a, int b, int c) {
    sides.setA(a);
    sides.setB(b);
    sides.setC(c);
}

void Triangle::Read() {
    int a, b, c;
    cout << "Enter sides a, b, c: ";
    cin >> a >> b >> c;
    Init(a, b, c);
}

void Triangle::Display() const {
    cout << toString() << endl;
}

string Triangle::toString() const {
    stringstream ss;
    ss << "Triangle with sides: " << sides.toString();
    return ss.str();
}

int Triangle::getCount() {
    return count;
}