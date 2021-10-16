#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> PalindromFilter(vector<string>& words, int wordLength)
{
	vector<string> res;
	for (auto str : words)
	{
		bool isPalindrom = true;
		int end = str.size();
		if (end < wordLength)
			continue;
		for (int i = 0; i < end / 2; i++)
		{
			if (str[i] != str[end - 1 - i])
			{
				isPalindrom = false;
				break;
			}
		}
		if (isPalindrom) 
			res.push_back(str);
	}
	return res;
}

int main()
{
    
	vector<string> test1 = {{"abacaba"},{"aba"},{"abc"}};
	vector<string> result;
	result = PalindromFilter(test1, 2);
	return 0;
}