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
    while (runs--){
        int n; cin >> n;
        vector<ll> vet(n);
        for(int i=0; i<n; i++) cin >> vet[i];

        ll last = 0;
        ll out = 0;
        for (int i=1; i<n; i++){
            if (vet[i] < vet[i-1]){
                ll a = vet[i];
                while (a < vet[i-1]){
                    a *= 2;
                    last++;
                }
            }
            else{
                ll a = vet[i-1] * 2;
                while (last > 0 && a <= vet[i]){
                    a *= 2;
                    last--;
                }
            }
            //debug(last);
            out += last;
        }
        cout << out << '\n';
    }

    return 0;
}
