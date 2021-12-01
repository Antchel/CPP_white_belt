#pragma once
#include <set>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include "Date.h"

using namespace std;

class Database {
public:
    void AddEvent(const Date& date, const string& event);
    bool DeleteEvent(const Date& date, const string& event);
    int  DeleteDate(const Date& date);

    set<string> Find(const Date& date) const;

    void Print() const;

private:
    map<Date, set<string>> dbSet;

};

ostream& operator << (ostream& stream, const Date& el);
