#include <iostream>
#include <math.h>
#include <vector>
#include <limits.h>

#define ll long long

using namespace std;

vector<ll> indexes;

ll mypow(ll base, ll exp)
{
    ll output = 1;
    while (exp--)
        output *= base;
    return output;
}

ll solve(ll idx)
{
    ll at_i = indexes.at(0);
    while (idx <= at_i)
    {

    }

    return -1;
}

int main()
{
    indexes.push_back(10);
    for (ll i = 2; i <= 16; i++)
    {
        ll pot = mypow(10, i - 1);
        indexes.push_back(9 * i * pot);
    }
    for (ll i : indexes)
        cout << i << endl;

    ll numInputs;
    cin >> numInputs;
    while (numInputs--)
    {
        ll in;
        cin >> in;
        cout << solve(in) << endl;
    }

    return 0;
}