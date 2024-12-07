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

        bool inc = true;
        bool dec = true;
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(int i=1; i<n; i++){
            if (in[i] < in[i-1]) inc = false;
            if (in[i] > in[i-1]) dec = false;
        }
        for(int i=0; i<n; i++){
            mx = max(mx, in[i]);
            mn = min(mn, in[i]);
        }
        if (inc){
            cout << mn << '\n';
            continue;
        }
        else if (dec){
            cout << mx << '\n';
            continue;
        }

        int lo = INT_MIN;
        int hi = INT_MAX;
        for(int i=1; i<n; i++){
            if (in[i] == in[i-1]) continue;
            if (in[i] > in[i-1]){
                hi = min(hi, (int)(floor((in[i] + in[i-1]) /2.0)));
            }
            else{
                lo = max(lo, (int)(ceil((in[i] + in[i-1]) / 2.0)));
            }
        }
        bool ok = true;
        for(int i=1; i<n; i++){
            if(abs(in[i] - lo) < abs(in[i-1] - lo)){
                ok = false;
                break;
            }
        }
        if (ok && lo <= hi) cout << lo << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}
