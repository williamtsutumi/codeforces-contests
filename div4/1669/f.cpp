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
        int n; cin >> n;
        vector<int> in(n);
        for(int i=0; i<n; i++) cin >> in[i];

        ll suml = 0, sumr = 0;
        ll out = 0;
        int l = 0, r = n-1;
        while(l <= r+1){
            if (suml > sumr){
                sumr += in[r];
                r--;
            }
            else if (suml < sumr){
                suml += in[l];
                l++;
            }
            else{
                if (l != 0) out = max(out, (ll)(n -r +l-1));
                suml += in[l];
                l++;
            }
        }
        cout << out << '\n';
    }

    return 0;
}
