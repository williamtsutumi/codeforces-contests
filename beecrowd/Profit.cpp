#include <iostream>
#include <vector>
#include <limits.h>
#include <string.h>

using namespace std;

vector<int> profits;
int costPerDay, numDays;
int sum[1001];

int solve(int openDays)
{
    if (openDays == 0)
        return 0;

    int output = 0;
    int its = numDays - openDays;
    for (int i = 0; i <= its; i++)
    {
        output = max(output, sum[i + openDays] - sum[i]);
    }
    return max(output, solve(openDays - 1));
}

int main()
{
    while (cin >> numDays >> costPerDay)
    {
        memset(sum, 0, sizeof(int) * 1001);
        profits.resize(numDays + 1);

        for (int i = 1; i <= numDays; i++)
        {
            int revenue;
            cin >> revenue;
            profits.at(i) = revenue - costPerDay;
        }
        if (numDays == 0)
        {
            cout << 0 << endl;
            continue;
        }
        else if (numDays == 1)
        {
            cout << max(0, profits.at(1)) << endl;
            continue;
        }

        sum[1] = profits.at(1);
        for (int i = 2; i <= numDays; i++)
            sum[i] = sum[i - 1] + profits.at(i);

        cout << solve(numDays) << endl;
    }

    return 0;
}