#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

ll solve(vector<int> &v, ll val, ll area){
    ll out = 0;
    for (int i=0; i<v.size(); i++){
        ll a = v[i] + val + val;
        out += a * a;
        if (out > area) return area+1;
    }
    return out;
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        ll n, area; cin >> n >> area;

        vector<int> sz(n);
        for(int i=0; i<n; i++) cin >> sz[i];

        ll hi = 1e9;
        ll lo = 0;
        while (lo <= hi){
            ll mid = (lo + hi) / 2;
            ll val = solve(sz, mid, area);
            if (val < area){
                lo = mid +1;
            }
            else{
                hi = mid -1;
            }
        }
        cout << lo << '\n';
    }

    return 0;
}
