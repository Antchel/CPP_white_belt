#include <iostream>
#include <exception>
#include <string>
using namespace std;

enum states {
    normal,
    exception,
    another_execp
};

string AskTimeServer(enum states state) {
    switch (state)
    {
    case normal:
        return "22:29:35";
        break;
    case states::exception:
        throw system_error(error_code());
        break;
    case another_execp:
        throw overflow_error("Wrong time");
        break;
    default:
        break;
    }
}


class TimeServer {
public:
    string GetCurrentTime() {
        try {
            last_fetched_time = AskTimeServer(states::another_execp);
            return last_fetched_time;
        }
        catch (std::exception& e) {
            throw e;
        }
    }
private:
    string last_fetched_time = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    }
    catch (std::exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
