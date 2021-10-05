#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int pos = -2;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'f') {
			pos++;
			if (!pos) {
				pos = i;
				break;
			}		
		}
	}
	cout << pos;
}