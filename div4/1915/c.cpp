#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        vector<ll> in(n);
        for (int i=0; i<n; i++) cin >> in[i];

        ll sum = 0;
        for (int i=0; i<n; i++) sum += in[i];

        double sq = sqrtl(sum);
        if (floor(sq) == sq){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }

    return 0;
}
