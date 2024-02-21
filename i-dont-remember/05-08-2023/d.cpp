#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
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
const double INF = 1e9 + 7;

int main()
{
    FFIO
    int n, q; cin >> n >> q;
    vector<pair<int,int>> vet(n);
    for(int i=0; i<n; i++){
        int a; cin >> a;
        vet[i] = {a,i};
    }
    sort(vet.begin(), vet.end());
    auto find = [&](vector<pair<int,int>> &vet, int a) -> bool {
        
    };



    return 0;
}