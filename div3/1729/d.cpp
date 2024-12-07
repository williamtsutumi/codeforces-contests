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
        vector<int> cost(n);
        vector<int> val(n);
        for(int i=0; i<n; i++) cin >> cost[i];
        for(int i=0; i<n; i++) cin >> val[i];

        vector<int> dif(n);
        for(int i=0; i<n; i++) dif[i] = val[i] - cost[i];

        sort(dif.begin(), dif.end());
        debug(dif);
    }

    return 0;
}
