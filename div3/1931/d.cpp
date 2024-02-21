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
        int n, x, y; cin >> n >> x >> y;
        vector<int> in(n);
        for(int i=0; i<n; i++) cin >> in[i];

        map<pair<int,int>, int> mp;
        ll out = 0;
        for(int i=0; i<n; i++){
            int v1, v2;
            v1 = in[i] % x;
            v2 = in[i] % y;
            out += mp[{(x - in[i] % x) % x, v2}];

            mp[{v1,v2}]++;
        }
        cout << out << '\n';
    }
    return 0;
}
