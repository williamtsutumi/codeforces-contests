#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int main()
{
    FFIO
    int r; cin >> r;
    while(r--){
        int n, k; cin >> n >> k;
        vector<int> in(n);
        for (int i=0; i<n; i++) cin >> in[i];

        bool ok = false;
        for (int i=0; i<n; i++){
            if (in[i] == k){
                ok = true;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
