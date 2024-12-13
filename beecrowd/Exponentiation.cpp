#include <iostream>

#define ll long long

using namespace std;

ll mod = 1e9 + 7;

ll solve(ll b, ll exp)
{
    if (exp == 0)
        return 1;

    if (exp % 2)
        return (b * solve(b, exp - 1)) % mod;
    else
    {
        ll half = solve(b, exp / 2);
        return (half * half) % mod;
    }
}

ll solve2(ll b, ll exp)
{
    ll out = 1;
    while (exp > 0)
    {
        if (exp % 2)
        {
            out *= b;
            out = out % mod;
        }

        exp >>= 1;
        b *= b;
        b = b % mod;
    }
    return out;
}

int main()
{
    ll numInput; cin >> numInput;
    while (numInput--)
    {
        ll base, pot; cin >> base >> pot;
        cout << solve2(base, pot) << endl;
    }

    return 0;
}