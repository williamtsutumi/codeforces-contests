#include <iostream>

using namespace std;

int mod = 1e9 + 7;

int main()
{
    int num; cin >> num;
    int output = 2;
    for (int i = 1; i < num; i++)
    {
        output *= 2;
        if (output > mod)
            output -= mod;
    }
    cout << output << endl;
    return 0;
}