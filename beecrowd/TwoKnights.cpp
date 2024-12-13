#include <iostream>

using namespace std;

long long solve(long long n)
{
    long long total = (n * n) * (n * n - 1) / 2;
    long long invalid = 4 * (n - 1) * (n - 2);
    return total - invalid;
}

int main()
{
    long long its; cin >> its;
    for (long long i = 1; i <= its; i++)
        cout << solve(i) << endl;

    return 0;
}