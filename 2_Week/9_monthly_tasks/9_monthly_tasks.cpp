#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	int dataSets, currMonth=0;
	cin >> dataSets;
	int daysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	vector<vector<string>> schedule(daysInMonth[currMonth]);
	for (int i = 0; i < dataSets; i++)
	{
		string cmd, val;
		int day;

		cin >> cmd;

		if (cmd == "ADD")
		{
			cin >> day >> val;
			schedule[day - 1].push_back(val);
		}
		else if (cmd == "NEXT")
		{
			currMonth++;
			if (currMonth > 11) currMonth = 0;
			vector<vector<string>> tmpsch(daysInMonth[currMonth]);
			if (tmpsch.size() >= schedule.size())
			{
				tmpsch = schedule;
			}
			else
			{
				for(int i = 0; i < tmpsch.size(); i++)
				{
					tmpsch[i] = schedule[i];
				}
				for (int i = tmpsch.size(); i < schedule.size(); i++)
				{
					tmpsch[tmpsch.size() - 1].insert(end(tmpsch[tmpsch.size() - 1]), begin(schedule[i]), end(schedule[i]));
				}
				schedule.clear();
				schedule = tmpsch;
			}
		}
		else if (cmd == "DUMP")
		{
			int day;
			cin >> day;
			int arrSize = schedule[day - 1].size();
			cout << arrSize << " ";
			for (int i = 0; i < arrSize;i++)
			{
				cout << schedule[day - 1][i] << " ";
			}
		}
	}
	return 0;
}