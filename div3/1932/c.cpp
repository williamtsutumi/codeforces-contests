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
        int n, mod; cin >> n >> mod;
        vector<int> in(n);
        for(int i=0; i<n; i++) cin >> in[i];
        string comand; cin >> comand;

        ll p = 1;
        for(int i=0; i<n; i++){
            p = ((in[i] % mod) * p) % mod;
        }

        int l = 0;
        int r = n-1;
        for(int i=0; i<comand.size(); i++){
            debug(i);
            cout << p << ' ';
            if (comand[i] == 'L'){
                int x = (in[l] % mod);
                l++;
                if (x == 0) continue;

                int k = 0;
                while ((p + k) % x != 0) k += mod;

                p = ((p + k) / x) % mod;
            }
            else if (comand[i] == 'R'){
                int x = (in[r] % mod);
                r--;
                if (x == 0) continue;

                int k = 0;
                while((p + k) % x != 0) k += mod;

                p = ((p + k) / x) % mod;
            }
        }
        cout << '\n';
    }

    return 0;
}
