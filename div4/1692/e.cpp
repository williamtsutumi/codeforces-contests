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
        int n, target; cin >> n >> target;

        vector<int> in(n);
        for(int i=0; i<n; i++) cin >> in[i];

        vector<ll> sums(n+1);
        sums[0] = 0;
        for(int i=1; i<=n; i++) sums[i] = sums[i-1] + in[i-1];

        if (sums[n] < target){
            cout << -1 << '\n';
            continue;
        }
        ll mx = INT_MIN;
        for(int i=0; i<=n; i++){
            ll search = target + sums[i];
            auto it = upper_bound(sums.begin(), sums.end(), search);
            ll idx = it - sums.begin() - 1;

            mx = max(mx, idx - i);
        }
        cout << n-mx << '\n';
    }

    return 0;
}
