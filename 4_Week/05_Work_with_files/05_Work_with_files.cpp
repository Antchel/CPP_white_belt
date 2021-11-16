#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> dict;
    ifstream file("input.txt");
    if (!file.is_open()) {
        cout << "Error!" << endl;
        return 1;
    }
    string line;
    while (getline(file, line)) {
        dict.push_back(line);
    }
    for (const string& l : dict) {
        cout << l << endl;
    }
    file.close();
    return 0;
}