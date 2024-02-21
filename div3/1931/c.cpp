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

        int f = in[0];
        int lo = 0;
        int hi = n-1;
        while(lo < n && in[lo] == f) lo++;
        while(hi >= 0 && in[hi] == f) hi--;
        int out = hi - lo + 1;

        f = in[n-1];
        lo = 0;
        hi = n-1;
        while(lo < n && in[lo] == f) lo++;
        while(hi >= 0 && in[hi] == f) hi--;
        out = min(out, hi-lo+1);
        out = max(0, out);

        cout << out << '\n';
    }

    return 0;
}
