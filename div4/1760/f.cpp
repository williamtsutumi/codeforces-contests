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

ll n, coins, days;

bool solve(vector<ll> &in, ll k){
    k++;
    ll out = 0;
    for (int i=0; i<days; i++){
        if (i % k < n) out += in[i%k];
    }
    return out >= coins;
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        cin >> n >> coins >> days;

        vector<ll> in(n);
        for (int i=0; i<n; i++) cin >> in[i];

        sort(in.begin(), in.end(), greater());
        ll sum = 0;
        int its = min(days, n);
        for (int i=0; i<its; i++){
            sum += in[i];
        }
        if (sum >= coins){
            cout << "Infinity\n";
            continue;
        }
        if (in[0] * days < coins){
            cout << "Impossible\n";
            continue;
        }

        ll hi = 3e5;
        ll lo = 1;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if (solve(in, mid)){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        cout << lo-1 << '\n';
    }

    return 0;
}

