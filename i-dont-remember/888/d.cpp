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
    ll runs; cin >> runs;
    for(int m=0; m<runs; m++){
        ll n; cin >> n;
        ll mx = (n)*(n+1)/2;
        vector<ll> vet(n);
        vet[0] = 0;
        for(ll i=1; i<n; i++) cin >> vet[i];
        // debug(vet);

        map<ll,ll> mp;
        for(ll i=0; i<n-1; i++){
            mp[vet[i+1]-vet[i]]++;
        }
        // debug(mp);

        ll count = 0;
        ll wrong = -1;
        bool ok = true;
        for(auto &[key,val]:mp){
            if (val == 2){
                wrong = key;
                count++;
            }
            else if (count || val > 2){
                cout << "NO" << endl;
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        if (wrong == -1){
            for(auto &[key,val]:mp){
                if (key > n+1) wrong = key;
            }
        }
        ll idx = 0;
        ll missing[2];
        ok = true;
        for(ll i=1; i<n; i++){
            if (mp[i] == 0){
                if (idx == 2){
                    cout << "NO" << endl;
                    ok = false;
                }
                missing[idx] = i;
                idx++;
            }
        }
        if (!ok) continue;
        if (missing[0] + missing[1] == wrong){
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    debug(runs);
    return 0;
}