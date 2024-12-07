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
        ll a, b, l; cin >> a >> b >> l;

        set<ll> st;
        for(ll i=1; i<=l; i*=a){
            for(ll j=1; j<=l; j*=b){
                if (l % (i*j)) continue;
                st.insert(l / (i*j));
            }
        }
        cout << st.size() << '\n';
    }
    return 0;
}
