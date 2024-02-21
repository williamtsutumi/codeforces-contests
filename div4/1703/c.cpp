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

int pmod(int n, int mod){
    return ((n % mod) + mod) % mod;
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        vector<int> in(n);
        for (int i=0; i<n; i++) cin >> in[i];

        vector<pair<int,string>> moves(n);
        for (int i=0; i<n; i++) cin >> moves[i].first >> moves[i].second;

        for (int i=0; i<n; i++){
            string mv = moves[i].second;
            int sz = mv.size();
            int cnt = 0;
            for (int j=0; j<sz; j++){
                if (mv[j] == 'D') cnt++;
                else cnt--;
            }
            in[i] = pmod(in[i] + cnt, 10);
        }

        for (int i=0; i<n; i++){
            cout << in[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
