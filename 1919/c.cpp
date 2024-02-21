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

        vector<int> in(n);
        for(int i=0; i<n; i++) cin >> in[i];

        vector<int> sizes;
        int cnt = 1;
        ll out = 0;
        for(int i=0;i<n-1;i++){
            if (in[i] >= in[i+1]){
                sizes.push_back(cnt);
                cnt = 0;
            }
            else{
                cnt++;
            }
        }
        sizes.push_back(cnt);

        debug(sizes);
        int mx = INT_MIN;
        for(int i=0; i<sizes.size();i++){
            out += sizes[i];
            mx = max(mx, sizes[i]);
        }

        out = out - ceil(mx/2.0);
        cout << max((long long)0, out) << endl;
    }

    return 0;
}
