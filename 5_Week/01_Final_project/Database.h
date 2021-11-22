#pragma once
#include <vector>
#include <string>
#include "Date.h"

using namespace std;

class Database {
public:
    void AddEvent(const Date& date, const string& event);
    bool DeleteEvent(const Date& date, const string& event);
    int  DeleteDate(const Date& date);

    vector<Date> Find(const Date& date) const;

    void Print() const;

private:
    vector<pair<string, string>> dbSet;

};