#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long double ld;
typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int n, cost;
vector<int> in;
vector<vector<ll>> dp;

ll solve(int idx, int bads){
    if (bads >= 30) return 0;
    if (idx == n) return 0;
    if (dp[idx][bads] != -1) return dp[idx][bads];

    ll val = in[idx] >> bads;

    ll good = val - cost + solve(idx+1, bads);
    ll bad = 0;
    if (bads < 30)
        bad = (val >> 1) + solve(idx+1, bads+1);

    ll out = max(good,bad);
    dp[idx][bads] = out;
    return out;
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        cin >> n >> cost;
        in.resize(n);
        for(int i=0; i<n; i++) cin >> in[i];

        dp.resize(n);
        for(int i=0; i<n; i++) dp[i].assign(30, -1);

        ll out = solve(0, 0);
        cout << out << '\n';
    }

    return 0;
}
