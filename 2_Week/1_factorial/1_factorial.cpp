
#include <iostream>

int factorial( int val)
{
	if (val <= 2)
		return val;
	int res;
	int *fact = new int[val + 1];
	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i <=val; i++)
	{
		fact[i] = fact[i - 1] * i;
	}
	res = fact[val];
	delete[]fact;
	return res;
}

using namespace std;

int main()
{
	cout << factorial(5);
}
