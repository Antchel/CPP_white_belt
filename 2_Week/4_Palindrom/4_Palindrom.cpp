#include <iostream>
#include <string>

using namespace std;

bool isPalindorm (string source)
{
	int end = source.size();
	for (int i = 0; i < end/2; i++)
	{
		if (source[i] != source[end - 1-i])
			return false;
	}
	return true;
}

int main()
{
	string str1 = "madam";
	string str2 = "Gentelman";
	string str3 = "X";
	cout << isPalindorm(str1) << endl;
	cout << isPalindorm(str2) << endl;
	cout << isPalindorm(str3) << endl;
}
