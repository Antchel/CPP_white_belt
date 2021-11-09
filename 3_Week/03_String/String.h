#pragma once
#include <string>

using namespace std;

class String
{
public:
	String();
	String(string init_str);
	~String();
	string ToString() const;
	void Reverse();
private:
	string str;
};
