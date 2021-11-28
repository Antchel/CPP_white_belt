#include "Database.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Database::AddEvent(const Date& date, const string& event) {

};
bool Database::DeleteEvent(const Date& date, const string& event) {
	return 0;
}
int  Database::DeleteDate(const Date& date) {
	return 0;
}

void Database::Find(const Date& date) const {
	
}

void Database::Print() const {
	for (const auto& el : dbSet) {
		for (const auto& str : el.second) {
			cout << setfill(4) << to_string(el.first.GetYear()) <<
				"-" << setfill(2) << to_string(el.first.GetMonth()) <<
				"-" << setfill(2) << to_string(el.first.GetDay()) << " " << str << endl;
		}
	}
}

ostream& operator << (ostream& stream, const Database& db) {
	
	return stream;
}