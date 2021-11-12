#include <string>
#include <iostream>

using namespace std;

struct Specialization
{
    explicit Specialization(string str) :spec(str) {}
    string spec;
};

struct Course
{
    explicit Course(string str) : course(str) {}
    string course;
};

struct Week
{
    explicit Week (string str) : week(str) {}
    string week;
};

struct LectureTitle {
    LectureTitle(Specialization new_spec, Course new_course, Week new_week) {
        specialization = new_spec.spec;
        course = new_course.course;
        week = new_week.week;
    }
        
    string specialization;
    string course;
    string week;
};

int main()
{
    LectureTitle title(
        Specialization("C++"),
        Course("WHite belt"),
        Week("4th")
    );
}