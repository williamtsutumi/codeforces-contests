#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
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
        vector<int> in(n);
        for(int i=0; i<n; i++) cin >> in[i];

        vector<int> cnt(31, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<=31; j++){
                if ((in[i] & (1 << j)) == 0) cnt[j]++;
            }
        }
        ll out = 0;
        for(int i=30; i>=0; i--){
            if (cnt[i] <= k){
                out |= (1 << i);
                k -= cnt[i];
            }
        }
        cout << out << '\n';
    }

    return 0;
}
