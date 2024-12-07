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

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        vector<int> in(n);
        for(int i=0; i<n; i++) cin >> in[i];

        vector<ll> sum(n+1);
        sum[0] = 0;
        for(int i=1; i<=n; i++) sum[i] = sum[i-1] + in[i-1];

        int q; cin >> q;
        for(int i=0; i<q; i++){
            int l, u; cin >> l >> u;

            int hi = n;
            int lo = l;
            ll mx = 0;
            while(lo <= hi){
                ll mid = (hi + lo) / 2;
                ll n = sum[mid] - sum[l-1];
                ll val = ((u + u - n+1) * n) / 2;
                if (val > mx){
                    mx = val;
                    lo = mid+1;
                }
                else{
                    hi = mid-1;
                }
            }
            cout << lo-1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
