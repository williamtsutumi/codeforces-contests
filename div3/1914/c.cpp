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

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n, k; cin >> n >> k;

        vector<int> first(n);
        vector<int> other(n);
        for (int i=0; i<n; i++) cin >> first[i];
        for (int i=0; i<n; i++) cin >> other[i];

        vector<int> maxother(n);
        maxother[0] = other[0];
        for (int i=1; i<n; i++){ maxother[i] = max(maxother[i-1], other[i]); }

        vector<int> sums(n);
        sums[0] = first[0];
        for (int i=1; i<n; i++) sums[i] = sums[i-1] + first[i];

        ll mx = 0;
        for (int i=0; i<min(n,k); i++){
            ll s = sums[i];
            ll rest = max(0, abs(k-i)-1)*maxother[i];
            ll val = s + rest;
            mx = max(mx, val);
        }
        cout << mx << '\n';
    }

    return 0;
}
