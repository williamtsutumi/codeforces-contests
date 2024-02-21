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
        map<int, int> mp;
        for(int i=0; i<n; i++){
            int val; cin >> val;
            mp[val]++;
        }
        int out = n;
        int cnt = 0;
        for(auto [k,v]:mp){
            int val = k;
            int notbits = ~val;
            if (notbits < 0) notbits += 2147483648;
            if (mp[val] > 0 && mp[notbits] > 0){
                int m = min(mp[notbits], mp[val]);
                cnt += m;
                mp[notbits] -= m;
                mp[val] -= m;
            }
        }
        cout << out - cnt << '\n';

    }

    return 0;
}
