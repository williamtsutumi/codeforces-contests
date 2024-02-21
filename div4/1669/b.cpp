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

        map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[in[i]]++;
        }
        int out = -1;
        for(auto [k,v]:mp){
            if (v >= 3){
                out = k;
                break;
            }
        }
        cout << out << '\n';

    }

    return 0;
}
