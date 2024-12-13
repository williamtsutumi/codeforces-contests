#include <iostream>

using namespace std;

int main()
{
    int in;
    while (cin >> in)
    {
        if (2 <= in && in <= 3)
            cout << "NO SOLUTION" << endl;
        else if (in == 4)
        {
            for (int i = 2; i <= in; i += 2)
                cout << i << " ";
            for (int i = 1; i <= in; i += 2)
                cout << i << " ";
            cout << endl;
        }
        else
        {
            for (int i = 1; i <= in; i += 2)
                cout << i << " ";
            for (int i = 2; i <= in; i += 2)
                cout << i << " ";
            cout << endl;
        }
    }

    return 0;
}