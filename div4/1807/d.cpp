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

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n, q; cin >> n >> q;

        vector<int> in(n);
        for (int i=0; i<n; i++) cin >> in[i];
        vector<ll> sums(n);
        sums[0] = in[0];
        for (int i=1; i<n; i++) sums[i] = sums[i-1] + in[i];

        ll original = sums[n-1];
        for (int i=0; i<q; i++){
            ll l, r, k; cin >> l >> r >> k;

            ll qsum = sums[r-1];
            if (l-2 >= 0) qsum -= sums[l-2];
            ll nowsum = (r-l+1) * k;
            ll out = original -qsum +nowsum;
            if ((original -qsum +nowsum) % 2) cout << "YES\n";
            else cout << "NO\n";
        }


    }

    return 0;
}
