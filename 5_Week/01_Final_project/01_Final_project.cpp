#include "Database.h"
#include "Date.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
    Database db;

    string command;
    while (getline(cin, command)) {
        if (command == "Add") {
            Date date(10,2,2020);
            string evnt;
            db.AddEvent(date, evnt);
        }
        else if (command == "Del") {
            //db.DeleteEvent();
        }
        else if (command == "Find") {
            Date date(10, 2, 2020);
            db.Find(date);
        }
        else if (command == "Print") {
            db.Print();
        }
    }

    return 0;
}