#include "SortedStrings.h"

void SortedStrings::AddString(string str)
{
	strings.insert(str);
}

vector<string> SortedStrings::GetSortedStrings()
{
	vector<string> sortstrings{};
	for (auto it = strings.begin(); it != strings.end(); it++) {
		sortstrings.push_back(*it);
	}
	return sortstrings;
}
