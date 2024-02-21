#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int main()
{
    int runs; cin >> runs;
    while(runs--){
        int n; cin >> n;

        vector<int> vet(n);
        for (int i=0; i<n; i++) cin >> vet[i];

        vector<ll> sum(n+1);
        sum[0] = 0;
        for (int i=1; i<=n;i++) sum[i] = sum[i-1] + vet[i-1];

        ll out = 0;
        for (int i=1; i<=n;i++){
            ll mx = -1;
            ll mn = LLONG_MAX;
            if (n % i != 0) continue;

            for (int j=1; j<=n; j+=i){
                ll t = sum[j + i - 1] - sum[j - 1];
                mx = max(mx, t);
                mn = min(mn, t);
            }
            out = max(out, mx - mn);
        }
        cout << out << endl;
    }

    return 0;
}
