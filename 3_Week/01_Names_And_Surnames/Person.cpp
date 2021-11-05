#include "Person.h"

void Person::ChangeFirstName(int year, const string& first_name) {
	f_name[year] = first_name;
}
void Person::ChangeLastName(int year, const string& last_name) {
	l_name[year] = last_name;
}
string Person::GetFullName(int year) {
	string f = GetFirstName(year);
	string l = GetLastName(year);

	if (f.empty() && l.empty()) return string("Incognito");
	if (f.empty()) return l + " with unknown first name";
	if (l.empty()) return f + " with unknown last name";
	return f + " " + l;
}

string Person::GetFirstName(int year)
{
	if (f_name.empty()) return string();
	if (f_name.count(year))
		return f_name[year];
	else if (f_name.size() == 1)
		return f_name[0];
	else {
		map<int, string>::iterator it = f_name.lower_bound(year);
		return (*--it).second;
	}
}

string Person::GetLastName(int year)
{
	if (l_name.empty()) return string();
	if (l_name.count(year))
		return l_name[year];
	else if (l_name.size() == 1)
		return l_name[0];
	else {
		map<int, string>::iterator it = l_name.lower_bound(year);
		return (*--it).second;
	}
}
