#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double
#define X real()
#define Y imag()

typedef long long C;
typedef complex<C> P;
typedef long long ll;
const double INF = 1e9 + 7;

int main()
{
    ll runs; cin >> runs;
    while(runs--){
        ld branch, b, h; cin >> branch >> b >> h;
        vector<ll> vet(branch);
        for (ll i=0; i<branch; i++){
            cin >> vet[i];
        }
        ld aux = (b * h / 2.0L);
        ld output = aux * branch;

        ld prop, diff;
        int h1, h2;
        for (ll i=0; i<branch-1; i++){
            h1 = vet[i+1];
            h2 = vet[i];
            diff = (h2 + h - h1);
            if (diff > 0){
                prop = (diff/h);
                output -= aux * prop * prop;
            }
        }
        cout << fixed;
        cout << setprecision(7) << output << endl;
    }

    return 0;
}