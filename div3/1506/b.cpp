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
        int n, k; cin >> n >> k;
        string in; cin >> in;

        int count = 0;
        for(int i=0; i<n; i++) if (in[i] == '*') count++;
        if (count == 1){
            cout << 1 << '\n';
            continue;
        }

        int l = -1;
        int r;
        for(int i=0; i<n; i++){
            if (in[i] == '*'){
                if (l == -1) l = i;
                r = i;
            }
        }

        int cnt = 2;
        while(r - l > k){
            int lo = 0;
            for(int i=k; i>0; i--){
                if (l+i < n && in[l+i] == '*'){
                    lo = l + i;
                    break;
                }
            }
            int hi = 0;
            for(int i=k; i>0; i--){
                if (r-i >= 0 && in[r-i] == '*'){
                    hi = r - i;
                    break;
                }
            }
            if (lo - l > r - hi){
                l = lo;
            }
            else{
                r = hi;
            }
            cnt++;
        }
        cout << cnt << '\n';
    }

    return 0;
}
