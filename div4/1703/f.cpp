#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long double ld;
typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

ll dp[200001];
vector<int> in;
vector<int> largers;

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        memset(dp, 0, sizeof(dp));
        int n; cin >> n;
        in.resize(n+1);
        largers.resize(n+1);
        for (int i=1; i<=n; i++) cin >> in[i];

        vector<int> v;
        ll out = 0;
        for (int i=1; i<=n; i++){
            if (in[i] >= i) continue;
            out += (ll)(lower_bound(v.begin(), v.end(), in[i]) - v.begin());
            v.push_back(i);
        }
        cout << out << '\n';
    }

    return 0;
}
