#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    cout << rand() % 100 << endl;
    cout << rand() % 10000 << " " << rand() % 10000 << endl;
    cout << 40 << endl;
    for (int i = 1; i <= 40; i++)
    {
        cout << rand() % 200 << " " << rand() % 90 << endl;
    }

    return 0;
}