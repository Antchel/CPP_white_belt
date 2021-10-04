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
	if (a == 0)
		cout << -c/b;
	if (b == 0)
		cout << sqrt(-c / a) << -sqrt(-c / a);
	

}