#pragma once
#include <string>
#include <stdexcept>

using namespace std;

class Date {
public:
    Date(int new_day, int new_month, int new_year);
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
private:
    int day;
    int month;
    int year;
};

bool operator<(const Date& lhs, const Date& rhs);
Date ParseDate(const string& date);