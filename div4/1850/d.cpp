#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
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
        int n, k; cin >> n >> k;

        vector<int> v(n);
        for(int i=0; i<n; i++) cin >> v[i];

        sort(v.begin(), v.end());
        int cnt = 0;
        int mx = cnt;
        for (int i=0; i<n-1; i++){
            if (abs(v[i] - v[i+1]) <= k) cnt++;
            else{
                mx = max(mx, cnt);
                cnt = 0;
            }
            if (i==n-2){
                mx = max(mx, cnt);
                cnt = 0;
            }
        }
        cout << n - mx - 1 << '\n';

    }

    return 0;
}
