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

        sort(in.begin(), in.end());

        if (in[0] != in[1]){
            cout << "YES\n";
            continue;
        }
        bool ok = false;
        for(int i=0; i<n; i++){
            if(in[i] % in[0] != 0){
                cout << "YES\n";
                ok = true;
                break;
            }
        }
        if (ok) continue;
        cout << "NO\n";
    }
    return 0;
}
/*
 * make a mod b such that all v[i] > mod
 * 
 *
 */

