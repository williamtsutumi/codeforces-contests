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
    int runs; cin >> runs;
    while(runs--){
        int n; cin >> n;
        vector<int> vet(n);
        for(int i=0; i<n; i++) {
            cin >> vet[i];
        }
        bool ok = true;
        vector<int> sums(n);
        sums[n-1] = 1;
        debug(sums);
        for(int i=1; i<n; i++){
            int diff = vet[i-1] - vet[i];
            if (diff == 0){
                sums[n-i-1] = sums[n-i];
            }
            else memset(sums + n-i-2-diff, sums[n-i], sizeof(int) * diff);
        }
        // reverse(sums.begin(), sums.end());
        // debug(vet);
        // debug(sums);
        for(int i=0; i<n-1; i++){
            if (vet[i] != sums[i]){
                ok = false;
                break;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}