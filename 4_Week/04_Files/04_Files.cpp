#include <fstream>
#include <filesystem>
#include <istream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ifstream file("input.txt");
	string fileData;
	if (!file.is_open()) {
		cout << "Current file doesn't consist" << "\n";
		return 1;
	}
	int n = 0, m = 0;
	getline(file, fileData, ' ');
	n = stoi(fileData);

	getline(file, fileData);
	m = stoi(fileData);
	int **arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			file >> arr[i][j];
			file.ignore(1);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setw(10);
			cout << arr[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	
	file.close();
	return 0;
}
