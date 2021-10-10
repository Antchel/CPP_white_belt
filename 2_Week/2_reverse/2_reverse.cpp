#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int>& arr)
{
	int end = arr.size();
	for (int i = 0; i < end/2; i++)
	{
		arr[i] ^= arr[end - i - 1];
		arr[end - i - 1] ^= arr[i];
		arr[i] ^= arr[end - i - 1];
	}
}

int main()
{
	vector<int> numbers{ 1,5,3,4,2,8 };
	reverse((numbers));
}
