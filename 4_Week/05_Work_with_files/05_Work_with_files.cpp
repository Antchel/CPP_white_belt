#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> dict;
    ofstream f("output.txt");
    ifstream file("input.txt");
    if (!file.is_open()) {
        cout << "Error!" << endl;
        return 1;
    }
    string line;
    while (getline(file, line)) {
        dict.push_back(line);
    }
    file.close();

    for (const string& l : dict) {
        f << l << endl;
    }
    f.close();

    return 0;
}