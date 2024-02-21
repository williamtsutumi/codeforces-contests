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
        int n, q; cin >> n >> q;
        vector<int> in(n);
        for (int i=0; i<n; i++){ cin >> in[i]; }

        vector<ll> sums(n);
        sums[0] = in[0];
        for (int i=1; i<n; i++){
            sums[i] = sums[i-1] + in[i];
        }

        vector<ll> precalc(n+1);
        ll firstval = 0;
        for (int i=0; i<n; i++){
            firstval += (i+1)*in[i];
        }
        precalc[0] = firstval;
        for (int i=1; i<=n; i++){
            precalc[i] = precalc[i-1] - sums[n-1];
        }
        debug(sums);
        debug(precalc);

        for (int i=0; i<q; i++){
            int start, dst, steps; cin >> start >> dst >> steps;
            start--;
            int last = start+dst*(steps-1);
            int k = last - start + 1;
            debug(start, dst, steps);
            debug(last, k);
            debug(precalc[start] - precalc[last]);
            debug(sums[n-1]-sums[last]);
            ll out = precalc[start] - precalc[last] - (k * (sums[n-1] - sums[last]));
            cout << out << ' ';
        }
        cout << '\n';
    }

    return 0;
}
