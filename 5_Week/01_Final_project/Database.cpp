#include "Database.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Database::AddEvent(const Date& date, const string& event) {
	dbSet[date].insert(event);
};
bool Database::DeleteEvent(const Date& date, const string& event) {
	if (dbSet.count(date) != 0) {
		auto it = dbSet[date].find(event);
		if (it != dbSet[date].end()) dbSet[date].erase(it);
		else return false;
		return true;
	}
	return false;
}
int  Database::DeleteDate(const Date& date) {
	auto it = dbSet.find(date);
	if (it != dbSet.end()) {
		int cnt = dbSet.at(date).size();
		dbSet.erase(it);
		return cnt;
	}
	return 0;
}

set<string> Database::Find(const Date& date) const {
	if (dbSet.count(date) != 0) {
		return dbSet.at(date);
	}
	return {};
}

void Database::Print() const {
	for (const auto& el : dbSet) {
		for (const auto& str : el.second) {
			cout << el.first << " " << str << endl;
		}
	}
}

ostream& operator << (ostream& stream, const Date& el) {
	stream << setw(4) << setfill('0') << to_string(el.GetYear()) <<
		"-" << setw(2) << setfill('0') << to_string(el.GetMonth()) <<
		"-" << setw(2) << setfill('0') << to_string(el.GetDay());
	return stream;
}