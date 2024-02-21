#ifdef ONLINE_JUDGE
  #define debug(x...)
#else
  #include "../../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const double INF = 1e9 + 7;

int main()
{
    int runs; cin >> runs;
    while(runs--){
        int n; cin >> n;
        vector<int> vet(n);
        for(int i=0; i<n; i++){
            cin >> vet[i];
        }
        vector<int> aux = vet;
        sort(vet.begin(), vet.end());
        bool ok = true;
        for(int i=0; i<n; i++){
            if (vet[i]%2 != aux[i]%2){
                cout << "NO" << endl;
                ok = false;
                break;
            }
        }
        if (ok)
            cout << "YES" << endl;
    }

    return 0;
}