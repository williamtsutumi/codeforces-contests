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
        pair<int,int> in[4];
        for (int i=0; i<4; i++) cin >> in[i].first >> in[i].second;

        int mxx, mnx, mxy, mny;
        mxx = mxy = INT_MIN;
        mnx = mny = INT_MAX;
        for(int i=0; i<4; i++){
            mxx = max(mxx, in[i].first);
            mnx = min(mnx, in[i].first);

            mxy = max(mxy, in[i].second);
            mny = min(mny, in[i].second);
        }
        int dx = mxx - mnx;
        int dy = mxy - mny;
        cout << dx * dy << '\n';
    }

    return 0;
}
