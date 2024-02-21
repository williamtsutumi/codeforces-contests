#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
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
    for(int i=0; i<runs; i++){
        int n; cin >> n;
        vector<int> vet(n);
        for(int j=0; j<n; j++) cin >> vet[j];

        sort(vet.begin(), vet.end());
        ll output = 0;
        for(int j=0; j<n/2; j++){
            output += vet[n-1-j] - vet[j];
        }
        // debug(vet);
        cout << output << endl;
    }

    return 0;
}