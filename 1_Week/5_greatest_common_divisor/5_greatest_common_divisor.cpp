#include <iostream>
#include <utility>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = min(a, b); i > 0; i--) {
        if (!(a % i ) && !(b % i)) {
            cout << i;
            break;
        }
    }
}