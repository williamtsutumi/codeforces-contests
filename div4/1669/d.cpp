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

        bool ok = true;
        bool hasb = false;
        bool hasr = false; 
        bool check = false;
        for(int i=0; i<=n; i++){
            if (i == n || in[i] == 'W'){
                if (check && (!hasb || !hasr)){
                    ok = false;
                    break;
                }
                hasb = false;
                hasr = false;
                check = false;
            }
            else if (in[i] == 'R'){hasr = true; check = true;}
            else{hasb = true; check = true;}
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }


    return 0;
}
