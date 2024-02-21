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
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        vector<ll> in(n);
        for(int i=0; i<n; i++) cin >> in[i];

        map<ll,ll> mp;
        for (int i=0; i<n; i++){
            ll a = in[i];
            ll its = ceil(sqrt(a));
            for (int j=2; j <= its; j++){
                if (a % j == 0){
                    a /= j;
                    mp[j]++;
                    j--;
                }
            }
            if (a > 1) mp[a]++;
        }
        bool ok = true;
        for (auto &[k,v] : mp){
            if (v % n != 0){
                cout << "NO\n";
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        cout << "YES\n";
    }

    return 0;
}
