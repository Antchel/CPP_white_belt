#include <iostream>

using namespace std;

int main()
{
    int lnum, rnum;
    cin >> lnum >> rnum;
    for (int i = lnum % 2 ? lnum + 1: lnum; i <= rnum; i += 2) {
            cout << i << " ";
    }
}
