#include <iostream>
#include <cmath>

using namespace std;

// y = ax^2 + bx + c
// D = b^2 - 4ac
// x = -b +/-sqrt(D)/(2a)

int main()
{
	int a, b, c;
	cin >> a >> b >> c; 
	if (a == 0) {
		if (b != 0)
			cout << -1.0 * c / b;
	}
	else {
		double d = b * b - 4 * a * c;
		if (d == 0)
			cout << -1.0*b / (2 * a);
		else if (d > 0){
			cout << 0.5 * (-b + sqrt(d)) / a << " " << 0.5 * (-b - sqrt(d)) / (a);
		}
	}
	
}