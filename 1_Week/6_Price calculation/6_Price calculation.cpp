#include <iostream>

using namespace std;

int main()
{
    double n, a, b, x, y, res;
    cin >> n >> a >> b >> x>> y;
    if (n > b)
        res = n * (1 - y*0.01);
    else if (n > a)
        res = n * (1 - x * 0.01);
    else
        res = n;
    cout << res;
}