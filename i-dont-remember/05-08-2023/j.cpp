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
const ll INF = 1e9 + 7;

int main()
{
    ll n, q; cin >> n >> q;
    vector<ll> vet(n);
    int in; cin >> in;
    vet[0] = in;
    for(ll i=1; i<n; i++){
        ll a; cin >> a;
        vet[i] = ((vet[i-1] + a)) % INF;
    }
    debug(vet);
    vector<ll> vet2(n);
    vet2[0] = 0;
    for(ll i=1; i<n; i++){
        vet2[i] = (vet2[i-1] + (((vet[i]-vet[i-1]) * vet[i-1]) % INF)) % INF;
    }
    debug(vet2);

    for(ll i=0; i<q; i++){
        ll a,b; cin >> a >> b;
        a--; b--;
        ll aux1, aux2;
        aux1 = aux2 = 0;
        if (a>=1){
            aux1 = vet[a-1];
            aux2 = vet[b] - vet[a];
            // debug(aux1, aux2);
        }
        cout << (ll)((vet2[b] - vet2[a] - ((aux1 * aux2) % INF)) % INF) << endl;
    }

    return 0;
}