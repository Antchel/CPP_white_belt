#include <iostream>
#include <exception>
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
        if (denominator == 0)
            throw invalid_argument("Can't devide on 0");
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

Rational& operator* (Rational a, Rational b) {
    Rational res(a.Numerator() * b.Numerator(), a.Denominator() * b.Denominator());
    return res;
}

Rational& operator/ (Rational a, Rational b) {
    if (b.Numerator() == 0)
        throw domain_error("DIvision by zero");
    Rational res(a.Numerator() * b.Denominator(), a.Denominator() * b.Numerator());
    return res;
}
int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    }
    catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    }
    catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}
