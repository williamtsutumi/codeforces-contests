#include <iostream>

#define ll long long

using namespace std;

ll mod = 1e9 + 7;
ll dp[1000001];

ll solve(ll sum)
{
    if (dp[sum] != 0)
        return dp[sum];

    if (sum == 0)
        return 1;

    ll seis = 6;
    for (ll i = min(sum, seis); i >= 1; i--)
    {
        dp[sum] += solve(sum - i) % mod;
    }
    return dp[sum];
}

int main()
{
    ll sum;
    while (cin >> sum)
    {
        cout << solve(sum) % mod << endl;
    }
    return 0;
}