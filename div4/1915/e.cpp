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
        int n; cin >> n;

        vector<int> in(n);
        for (int i=0; i<n; i++) cin >> in[i];

        for (int i=0; i<n; i+=2) in[i] = -in[i];

        vector<ll> sums(n);
        sums[0] = in[0];
        for (int i=1; i<n; i++) sums[i] = sums[i-1] + in[i];

        map<ll,ll> mp;
        for (int i=0; i<n; i++) mp[sums[i]]++;

        bool ok = false;
        for (auto &[k,v]:mp){
            if (v > 1 || k == 0){
                ok = true;
                break;
            }
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
