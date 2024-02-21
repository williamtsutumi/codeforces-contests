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
        vector<int> in;
        for (int i=0; i<n; i++){
            int a; cin >> a;
            if (a <= n) in.push_back(a);
        }
        map<int,int> mp;
        for (int i=0; i<in.size(); i++){
            mp[in[i]]++;
        }

        vector<int> cnt(200002, 0);
        for (int i=0; i<=n; i++){
            int val = mp[i];
            if (val == 0) continue;

            for (int j=i; j<=n; j+=i){
                cnt[j-1] += val;
            }
        }
        int mx = 0;
        for (int i=0; i<=n; i++){
            mx = max(mx, cnt[i]);
        }
        cout << mx << '\n';
    }

    return 0;
}
