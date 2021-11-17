#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Name {
public:
    Name(){}
    explicit Name(string new_name) : name(new_name) {}
    string name;
};

class Surname {
public:
    Surname(){}
    explicit Surname(string new_surname) : surname(new_surname) {}
    string surname;
};

class Day {
public:
    Day() { day = 0; }
    explicit Day(int new_day) :day(new_day) {}
    int day;
};

class Month {
public:
    Month() { month = 0; }
    explicit Month(int new_month) :month(new_month) {}
    int month;
};

class Year {
public:
    Year() { year = 0; }
    explicit Year(int new_year) :year(new_year) {}
    int year;
};

class Student
{
public:
    Student(Name new_name, Surname new_surname, Day day, Month month, Year year) 
        : name(new_name.name), surname(new_surname.surname), birthday(day.day), birthmonth(month.month), birthyear(year.year) {}
    string name;
    string surname;
    int birthday;
    int birthmonth;
    int birthyear;
};

int main()
{
    vector<Student> studentsList;
    int dataSets, requestsCnt;
    cin >> dataSets;
    for (int i = 0; i < dataSets; i++) {
        Name name;
        Surname surname;
        Day day;
        Month month;
        Year year;
        cin >> name.name >> surname.surname >> day.day >> month.month >> year.year;
        studentsList.push_back({name, surname, day, month, year });
    }
    cin >> requestsCnt;
    for (int i = 0; i < requestsCnt; i++) {
        try
        {
            string request;
            int studentId;
            cin >> request >> studentId;
            if (request == "name") {
                cout << studentsList.at(studentId - 1).name << " " 
                    << studentsList.at(studentId - 1).surname << endl;
            }
            else if (request == "date") {
                cout << studentsList.at(studentId - 1).birthday 
                    << "." << studentsList.at(studentId - 1).birthmonth << "." 
                    << studentsList.at(studentId - 1).birthyear << endl;
            }
            else
                cout << "Bad request" << endl;
        }
        catch (const std::exception&)
        {
            cout << "Bad request" << endl;
        }

    }
    return 0;
}