#include <iostream>

using namespace std;

#define ll long long

ll solve(ll l, ll c)
{
    if (l >= c)
    {
        if (l % 2)
            return (l - 1) * (l - 1) + c;
        else
            return l * l - c + 1;
    }
    else
    {
        if (c % 2)
            return c * c - l + 1;
        else
            return (c - 1) * (c - 1) + l;
    }
}

int main()
{
    ll numInput; cin >> numInput;
    for (ll i = 0; i < numInput; i++)
    {
        ll l, c; cin >> l >> c;
        cout << solve(l, c) << endl;
    }

    return 0;
}