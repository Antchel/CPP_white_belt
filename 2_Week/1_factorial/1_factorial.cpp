
#include <iostream>

int factorial( int val)
{
	if (val < 0)
		return -1;
	if (val <= 2)
		return val;
	int res, fact_prev;
	fact_prev = 2;
	for (int i = 3; i <= val; i++)
	{
		res = fact_prev * i;
		fact_prev = res;
	}
	return res;
}

using namespace std;

int main()
{
	cout << factorial(5);
}
