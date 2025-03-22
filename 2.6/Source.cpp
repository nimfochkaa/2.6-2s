#include <iostream>
#include "Triangle.h"

using namespace std;

int main() {
    Triangle t1;
    t1.Read();
    t1.Display();

    cout << "Area of t1: " << t1.getArea() << endl;

    double A1, B1, C1;
    t1.getAngles(A1, B1, C1);
    cout << "Angles of t1: A = " << A1 << ", B = " << B1 << ", C = " << C1 << endl;

    cout << "---------------------------" << endl;

    Triangle t2(3, 4, 5);
    t2.Display();

    cout << "Area of t2: " << t2.getArea() << endl;

    double A2, B2, C2;
    t2.getAngles(A2, B2, C2);
    cout << "Angles of t2: A = " << A2 << ", B = " << B2 << ", C = " << C2 << endl;

    cout << "---------------------------" << endl;

    Triangle t3 = t2;
    cout << t3.toString() << endl;

    cout << "Total Triangles: " << Triangle::getCount() << endl;
    cout << "Total Triads: " << Triangle::Triad::getCount() << endl;

    return 0;
}