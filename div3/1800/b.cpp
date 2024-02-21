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
        int n, k; cin >> n >> k;
        string in; cin >> in;

        map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[in[i]]++;
        }
        ll sum = 0;
        for(auto [k,v]:mp){
            sum += min(mp[tolower(k)], mp[toupper(k)]);
        }
        sum /= 2;

        ll out = 0;
        
        for(auto [key,v]: mp){
            char low = tolower(key);
            char up = toupper(key);
            int diff = abs(mp[low] - mp[up]);
            diff /= 2;
            if (diff <= k){
                mp[low] = 0;
                mp[up] = 0;
                out += diff;
                k -= diff;
            }
        }
        sum += out;
        cout << sum << '\n';
    }

    return 0;
}
