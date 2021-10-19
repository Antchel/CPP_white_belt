#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int dataSets;
    vector<bool> q;
    cin >> dataSets;
    while(dataSets--)
    {


        string operation;
        cin >> operation;

        if (operation == "WORRY_COUNT")
        {
            cout << count(begin(q), end(q), true) << endl;
        }else {
            int index;
            if (operation == "COME")
            {
                cin >> index;
                q.resize(q.size() + index, false);
            } else if (operation == "WORRY")
            {
                cin >> index;
                q[index] = true;
            }
        }
    }
    

}