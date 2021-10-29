#include <iostream>
#include <map>

using namespace std;

int main()
{
	int datasets;
	std::cin >> datasets;
	while (datasets--)
	{
		map<char, int> m1, m2;
		string word1, word2;
		cin >> word1 >> word2;
		for(const auto& ch: word1)
			m1[ch]++;
		for (const auto& ch : word2)
			m2[ch]++;
		if (m1 == m2) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}