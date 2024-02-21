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

ll solve(vector<ll> &sums, int q){
    auto lo = lower_bound(sums.begin(), sums.end(), q);
    if (lo == sums.end()) return -1;
    return lo - sums.begin();
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n, q; cin >> n >> q;
        vector<int> in(n);
        for(int i=0; i<n; i++) cin >> in[i];

        sort(in.begin(), in.end(), greater());
        vector<ll> sums(n+1);
        sums[0] = 0;
        for(int i=1; i<=n; i++) sums[i] = sums[i-1] + in[i-1];
        for(int i=0; i<q; i++){
            int querie; cin >> querie;
            cout << solve(sums, querie) << '\n';
        }
    }

    return 0;
}
