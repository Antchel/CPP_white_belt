#include "Database.h"
#include "Date.h"
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    try {
        Database db;

        string commandLine;
        while (getline(cin, commandLine)) {
            stringstream ss(commandLine);
            string command;
            ss >> command;
            if (command == "Add") {
                string dateStr, eventStr;
                ss >> dateStr >> eventStr;
                Date date = ParseDate(dateStr);
                db.AddEvent(date, eventStr);
            }
            else if (command == "Del") {
                string dateStr, eventStr;
                ss >> dateStr;
                if (!ss.eof()) {
                    ss >> eventStr;
                }
                Date date = ParseDate(dateStr);
                if (eventStr.empty()) {
                    int cnt = db.DeleteDate(date);
                    if (cnt)
                        cout << "deleted " << cnt << " rows" << endl;
                    else
                        cout << "Nothing to delete" << endl;
                }
                    
                else {
                    if (db.DeleteEvent(date, eventStr))
                        cout << "event deleted" << endl;
                    else
                        cout << "event doesn't alreay exist" << endl;
                    
                }
                    
            }
            else if (command == "Find") {
                string dateStr;
                ss >> dateStr;
                Date date = ParseDate(dateStr);
                set<string> events;
                events = db.Find(date);

                for (auto it = events.begin(); it != events.end(); it++) {
                    cout << *it << endl;
                }
            }
            else if (command == "Print") {
                db.Print();
            }
            else {
                cout << "Unknown command " + command << endl;
            }
        }
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
    
    return 0;
}