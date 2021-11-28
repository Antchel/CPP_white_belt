#include "Date.h"

Date::Date(int new_day, int new_month, int new_year) {
    if (new_year < 0)
        throw logic_error("Year can't be negative, like " + to_string(year));
    year = new_year;

    int leap = ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
    int daysPerMonth[12] = { 31,28+leap,31,30,31,30,31,31,30,31,30,31 };

    if (month < 1 && month > 12)
        throw logic_error("Month value is invalid: " + to_string(month));
    month = new_month;
    if (new_day < 1 && new_day > daysPerMonth[month])
        throw logic_error("Day value is invalid: " + to_string(day));
    day = new_day;
};

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
	long lhs_days = 0, rhs_days = 0;
	lhs_days = lhs.GetYear() * 365 + lhs.GetMonth() * 30 + lhs.GetDay();
	rhs_days = rhs.GetYear() * 365 + rhs.GetMonth() * 30 + rhs.GetDay();
	return lhs_days < rhs_days ? true : false;
}