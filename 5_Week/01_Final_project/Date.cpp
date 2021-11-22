#include "Date.h"

int Date::GetYear() const {
	return year;
}
int Date::GetMonth() const {
	return month;
}
int Date::GetDay() const {
	return day;
}

bool operator<(const Date& lhs, const Date& rhs) {
	
}