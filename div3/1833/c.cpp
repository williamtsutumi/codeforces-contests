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
    while (r--){
        int n; cin >> n;

        vector<int> v(n);
        for (int i=0; i<n; i++) cin >> v[i];

        bool hasOdd = false;
        for (int i=0; i<n; i++){
            if (v[i] % 2 == 1){
                hasOdd = true;
                break;
            }
        }
        if (!hasOdd){
            cout << "YES\n";
            continue;
        }

        int mn = INT_MAX;
        for (int i=0; i<n; i++){
            if (v[i] % 2 == 1){
                mn = min(mn, v[i]);
            }
        }
        bool ok = true;
        for (int i=0; i<n; i++){
            if (v[i] % 2 == 0){
                if (v[i] <= mn){
                    ok = false;
                    break;
                }
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
