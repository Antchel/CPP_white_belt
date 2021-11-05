#pragma once
#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

class Person
{
public:
	void ChangeFirstName(int year, const string& first_name);
	void ChangeLastName(int year, const string& last_name);
	string GetFullName(int year);

private:
	map<int, string> f_name;
	map<int, string> l_name;
	string GetFirstName(int year);
	string GetLastName(int year);
};