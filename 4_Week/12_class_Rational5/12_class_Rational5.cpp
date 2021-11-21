#include <iostream>
#include <map>
#include <set>
#include <vector>
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

bool operator == (Rational a, Rational b) {
    return ((a.Numerator() == b.Numerator()) && (a.Denominator() == b.Denominator()));
};

Rational operator-(Rational a, Rational b) {
    Rational res{ a.Numerator() * b.Denominator() -
                    b.Numerator() * a.Denominator(), a.Denominator() * b.Denominator() };
    return res;
};

bool operator < (const Rational& left, const Rational& right) {
    return (((left - right).Numerator()) < 0);
}

int main() {
    {
        const set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
