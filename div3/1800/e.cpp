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
        string from, to; cin >> from >> to;

        map<int,int> mp1, mp2;
        for(int i=0; i<n; i++){
            mp1[from[i]]++;
            mp2[to[i]]++;
        }
        if (mp1 != mp2){
            cout << "NO\n";
            continue;
        }

        if (n >= 2*k){
            cout << "YES\n";
            continue;
        }

        bool ok = true;
        int its = min(n, 2*k -n);
        int s = max(0, (int)ceil(n / 2.0) - (int)ceil(its/2.0));
        for(int i=0; i<its; i++){
            if (from[s+i] != to[s+i]) ok = false;
        }
        if (ok){
            cout << "YES\n";
            continue;
        }
        else{
            cout << "NO\n";
            continue;
        }
    }

    return 0;
}
