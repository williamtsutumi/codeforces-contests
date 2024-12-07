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
        ll n; cin >> n;

        ll p = 1;
        ll s = 6;
        ll out = n;
        while((n+s)/(p*10) > 0){
            out += ((n+s)/(p*10)) *p;
            p *= 10;
            s = 6*p;
        }
        cout << out << '\n';
    }
    return 0;
}
