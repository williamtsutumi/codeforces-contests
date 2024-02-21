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
        string in; cin >> in;

        if (n % 2){
            cout << -1 << '\n';
            continue;
        }

        map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[in[i]]++;
        }
        int mx = -1;
        for(auto [k,v]:mp){
            mx = max(mx, v);
        }
        if (mx > n -mx){
            cout << -1 << '\n';
            continue;
        }
        else{
            int cnt = 0;
            map<int,int> mp2;

            for(int i=0; i<n/2; i++){
                if (in[i] == in[n-1-i]){
                    cnt++;
                    mp2[in[i]]++;
                }
            }
            int mx2 = -1;
            for(auto [k,v]:mp2){
                mx2 = max(mx2, v);
            }
            cout << max((int)ceil(cnt/2.0), mx2) << '\n';
            continue;
        }
    }

    return 0;
}
