#include <iostream>

using namespace std;

int main()
{
    char input; cin >> input;
    char last = input;
    int output = 1;
    int max_temp = 1;
    while (cin >> input)
    {
        if (input == last)
        {
            max_temp++;
            output = max(output, max_temp);
        }
        else
        {
            last = input;
            max_temp = 1;
        }

    }
    cout << output << endl;

    return 0;
}