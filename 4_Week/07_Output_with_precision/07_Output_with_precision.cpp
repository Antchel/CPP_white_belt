#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	ifstream file("input.txt");
	if (!file.is_open()) {
		cout << "File doesn't opened" << endl;
		return 1;
	}
	string line;
	vector<double> arr;
	while (getline(file, line)) {
		arr.push_back(atof(line.c_str()));
	}
	cout << fixed << setprecision(3);
	for (const double& el : arr) {
		cout << el << endl;
	}
	return 0;
}
