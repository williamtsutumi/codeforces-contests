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
    /*
     * 6 5 2 3 4 1
     * 6 11 13 16 20 21
     * 0 5 1 4 2 3
     * 1 6 2 5 3 4
     *
     * 6 5 4 1 2 3
     * 6 11 15 17 18 21
     * 0 5 3 5
     *
     * n=3
     * 3 2 1
     *
     * n=8
     * 8 7 2 5 4 3 6 1
     * 8 15 17 22 26 29 35 36
     * 0 7 1 6 2 5 3 4
     *
     */
    FFIO;
    int r; cin >> r;
    while(r--){
        ll n; cin >> n;
        if (n == 1){
            cout << 1 << '\n';
            continue;
        }
        if (n%2 == 1){
            cout << -1 << '\n';
            continue;
        }
        cout << n << ' ' << n-1 << ' ';
        int its = (n-2)/2;
        int l = 0;
        int r = n-1;
        for(int i=0; i<its; i++){
            l += 2;
            r -= 2;
            cout << l << ' ' << r << ' ';
        }
        cout << '\n';
    }

    return 0;
}
