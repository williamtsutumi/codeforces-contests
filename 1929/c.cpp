#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
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
        ll k, mx, coins; cin >> k >> mx >> coins;

        ll sum = 1;
        bool ok = true;
        for (int i=0; i<mx; i++){
            sum += sum / (k-1) + 1;
            if (sum > coins){
                ok = false;
                break;
            }
        }
        if (ok && sum <= coins) cout << "YES\n";
        else cout << "NO\n";
    }
    /*
     * bet * (k-1) > lost
     * bet > lost / (k-1)
     *
     *
     */

    return 0;
}
