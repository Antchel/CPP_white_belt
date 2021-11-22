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
};

Rational& operator/ (Rational a, Rational b) {
    if (b.Numerator() == 0)
        throw domain_error("DIvision by zero");
    Rational res(a.Numerator() * b.Denominator(), a.Denominator() * b.Numerator());
    return res;
};

Rational& operator+(Rational a, Rational b) {
    Rational res{ a.Numerator() * b.Denominator() +
                    b.Numerator() * a.Denominator(), a.Denominator() * b.Denominator() };
    return res;
};

Rational& operator-(Rational a, Rational b) {
    Rational res{ a.Numerator() * b.Denominator() -
                    b.Numerator() * a.Denominator(), a.Denominator() * b.Denominator() };
    return res;
};

istream& operator>> (istream& stream, Rational& node) {
    int num, denum;
    char s;
    stream >> num >> s >> denum;
    if (stream && s == '/') {
        node = Rational(num, denum);
    }

    return stream;
}

ostream& operator<< (ostream& stream, const Rational& node) {
    return stream << node.Numerator() << '/' << node.Denominator();
}

int main() {
    try {
        Rational a, b;
        char op;

        cin >> a >> op >> b;
        switch (op)
        {
        case '/':
            cout << Rational(a / b) << endl;
            break;
        case '+':

            cout << Rational(a + b) << endl;
            break;
        case '-':
            cout << Rational(a - b) << endl;
            break;
        case '*':
            cout << Rational(a * b) << endl;
            break;
        default:
            cout << "Unknown operation" << endl;
            break;
        }
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
}
