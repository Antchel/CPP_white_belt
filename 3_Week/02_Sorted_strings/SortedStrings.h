#pragma once
#include <string>
#include <vector>
#include <set>

using namespace std;

class SortedStrings{
public:
	void AddString(string str);
	vector<string> GetSortedStrings();

private:
	multiset<string> strings;
};
