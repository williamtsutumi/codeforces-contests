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

        vector<int> dp(n);
        for(int i=0; i<n-1; i++){
            int start = i;
            while(i+1 < n && in[i+1] == in[i]){
                i++;
            }
            for(int j=start; j<=i; j++){
                dp[j] = i+1;
            }
        }

        int q; cin >> q;
        while(q--){
            int l, r; cin >> l >> r;
            l--; r--;

            if (dp[l] > r) cout << -1 << ' ' << -1 << '\n';
            else cout << l+1 << ' ' << dp[l]+1 << '\n';
        }
        cout << '\n';
            
    }

    return 0;
}
