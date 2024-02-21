#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int dp[200000];
vector<int> in;

int solve(vector<int> &in, int idx){
    if (idx == in.size()) return 0;
    if (idx > in.size()) return INF;
    if (dp[idx] != -1) return dp[idx];

    dp[idx] = min(1 + solve(in, idx+1), solve(in, idx + in[idx] + 1));
    return dp[idx];
}

int main()
{
    FFIO
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        in.resize(n);
        for (int i=0; i<n; i++) cin >> in[i];

        memset(dp, -1, sizeof(dp));
        cout << solve(in, 0) << '\n';
    }

    return 0;
}
