#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

string maiorNum(string num, int remove)
{
    if (remove == 0)
        return num;
    
    num.erase(3);
    return num;
}

int main()
{
    int digitos, remove;
    while (cin >> digitos >> remove)
    {
        string num;
        cin >> num;

        cout << maiorNum(num, remove) << endl;
    }
}