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
        ll lins, cols, num; cin >> lins >> cols >> num;
        num--;
        ll l = num % lins;
        ll c = num / lins;
        cout << (ll)(1 + (l * cols + c)) << '\n';
    }

    return 0;
}
