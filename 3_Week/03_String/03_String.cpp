#include <iostream>
#include "String.h"

int main()
{
    String str("Alive");

    cout << str.ToString() << endl;

    str.Reverse();
    cout << str.ToString() << endl;

    const String& ref_s = str;
    string tmp = ref_s.ToString();
    cout << tmp << endl;
    String empty;
    cout << "\""<< empty.ToString() << "\"" << endl;

}