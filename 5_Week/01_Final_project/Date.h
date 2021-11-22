#pragma once

class Date {
public:
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
private:
    int day;
    int month;
    int year;
};

bool operator<(const Date& lhs, const Date& rhs);
