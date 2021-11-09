#include "String.h"
#include <algorithm>

String::String()
{

}

String::String(string init_str)
{
	str = init_str;
}

String::~String()
{
	str.clear();
}

string String::ToString() const
{
	return str;
}

void String::Reverse()
{
	reverse(str.begin(), str.end());
}

