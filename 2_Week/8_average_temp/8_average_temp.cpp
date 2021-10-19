#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    int days, avg;
    cin >> days;
    vector<int> tempArr(days);
    for (int i  = 0; i < days; i++)
    {
        cin >> tempArr[i];
    }
    avg = accumulate(begin(tempArr), end(tempArr), 0) / tempArr.size();

    vector<int> result;
    for (int i = 0; i < tempArr.size(); i++)
    {
        if (tempArr[i] > avg)
            result.push_back(i);
    }
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

}