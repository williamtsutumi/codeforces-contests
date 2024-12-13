#include <iostream>
#include <vector>
#include <limits.h>
#include <string.h>

using namespace std;

#define ll long long

ll dp[2][10000];
vector<ll> in;

ll solve2(ll size)
{
    for (ll i = 2; i < size; i++)
    {
        ll aux = i % 2;
        for (ll j = 0; j < size - i; j++)
        {
            // ll dir = in[i + j] + min(dp[i - 2][j], dp[i - 2][j + 1]);
            // ll esq = in[j] + min(dp[i - 2][j + 1], dp[i - 2][j + 2]);
            // dp[i][j] = max(esq, dir);
            
            ll dir = in[i + j] + min(dp[aux][j], dp[aux][j + 1]);
            ll esq = in[j] + min(dp[aux][j + 1], dp[aux][j + 2]);
            dp[aux][j] = max(esq, dir);
        }
    }
    // return dp[size - 1][0];
    ll l = (size % 2 == 0) ? 1 : 0;
    return dp[l][0];
}

/*
dp[tamanho][i]
solve(ll i, ll j) {
    a = in[i] + min(solve(i + 2, j), solve(i + 1, j - 1));
    b = in[j] + min(solve(i, j - 2), solve(i + 1, j - 1));
    return max(a, b);
}
*/

ll solve(ll from, ll to)
{
    if (dp[from][to] != -1)
        return dp[from][to];

    if (from == to)
        return 0;

    ll takeLeft, takeRight;
    // jogador um
    if ((to - from) % 2 == 1)
    {
        takeLeft = in[from] + solve(from + 1, to);
        takeRight = in[to] + solve(from, to - 1);
        dp[from][to] = max(takeLeft, takeRight);
    }
    // jogador dois
    else
    {
        takeLeft = solve(from + 1, to);
        takeRight = solve(from, to - 1);
        dp[from][to] = min(takeLeft, takeRight);
    }
    return dp[from][to];
}

int main()
{
    ll numInputs;
    while (cin >> numInputs)
    {
        memset(dp, -1, sizeof(ll) * 2 * 10000);
        in.clear();

        for (ll i = 0; i < numInputs; i++)
        {
            ll input;
            cin >> input;
            in.push_back(input);
        }
        //**********************************
        for (ll i = 0; i < numInputs; i++)
            dp[0][i] = in[i];

        for (ll i = 0; i < numInputs - 1; i++)
            dp[1][i] = max(in[i], in[i + 1]);
        //**********************************
        cout << solve2(numInputs) << endl;
    }

    return 0;
}