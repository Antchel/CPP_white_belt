#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

class Rational {
public:
    Rational() {
        this->numerator = 0;
        this->denominator = 1;
    }

    Rational(int numerator, int denominator) {
        if (!numerator) {
            this->numerator = numerator;
            this->denominator = 1;
        }
        
        int val = gcd(numerator, denominator);
        this->numerator = numerator / val;
        this->denominator = denominator / val;

        if (this->denominator < 0) {
            this->numerator *= -1;
            this->denominator *= -1;
        }
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;

};

bool operator== (Rational a, Rational b) {
    return ((a.Numerator() == b.Numerator()) && (a.Denominator() == b.Denominator()));
};
Rational& operator+(Rational a, Rational b) {
    Rational res{   a.Numerator()* b.Denominator() + 
                    b.Numerator()* a.Denominator(), a.Denominator()*b.Denominator()};
    return res;
};

Rational& operator-(Rational a, Rational b) {
    Rational res{ a.Numerator() * b.Denominator() -
                    b.Numerator() * a.Denominator(), a.Denominator() * b.Denominator() };
    return res;
};
int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
