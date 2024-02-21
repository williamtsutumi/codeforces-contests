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
        for (int i=0; i<n; i++) cin >> vet[i];

        int sum = vet[0];
        int out = vet[0];
        int mn = min(vet[0], 0);
        for (int i=1; i<n; i++){
            if (PMOD(vet[i], 2) == PMOD(vet[i-1], 2)){
                mn = 0;
                sum = 0;
            }
            sum += vet[i];
            out = max(out, sum - mn);
            mn = min(mn, sum);
        }
        cout << out << '\n';
    }

    return 0;
}
