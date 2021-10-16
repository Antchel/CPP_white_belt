#include <iostream>

using namespace std;

void UpdateIfGreater(const int first, int& second)
{
	if (first > second)
		second = first;
}

int main()
{
	int a = 5, b = 0;

	cout << b << endl;
	UpdateIfGreater(a, b);
	cout << b << endl;


}