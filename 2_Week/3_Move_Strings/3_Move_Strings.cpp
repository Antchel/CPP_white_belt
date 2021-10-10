#include <vector>
#include <string>
#include <iostream>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& dest)
{
	for (auto str : source)
		dest.push_back(str);
	source.clear();
}

int main()
{
	vector<string> src = { "A", "b", "c" };
	vector<string> dst = { "D" };
	MoveStrings(src, dst);
}
