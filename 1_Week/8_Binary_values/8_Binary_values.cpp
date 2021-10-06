#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int value;
	cin >> value;
	vector<int> res;
	while (value >= 1)
	{
		res.push_back(value % 2);
		value /= 2;
	}
	for (int i = res.size() - 1; i >= 0; i--)
		cout << res[i];
}