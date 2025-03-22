#pragma once
#include <string>

using namespace std;

class Triangle {
public:
    class Triad {
    private:
        int a, b, c;
        static int count;
    public:
        Triad();
        Triad(int a, int b, int c);
        Triad(const Triad& other);
        ~Triad();

        int getA() const;
        int getB() const;
        int getC() const;

        void setA(int value);
        void setB(int value);
        void setC(int value);

        Triad& operator=(const Triad& other);

        Triad& operator++();     // prefix
        Triad operator++(int);   // postfix
        Triad& operator--();
        Triad operator--(int);

        int Sum() const;
        string toString() const;

        static int getCount();
    };

private:
    Triad sides;
    static int count;

public:
    Triangle();
    Triangle(int a, int b, int c);
    Triangle(const Triangle& other);
    ~Triangle();

    Triangle& operator=(const Triangle& other);

    void Init(int a, int b, int c);
    void Read();
    void Display() const;
    string toString() const;

    static int getCount();
    double getArea() const;
    void getAngles(double& A, double& B, double& C) const;
};