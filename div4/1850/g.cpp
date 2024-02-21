#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        vector<pair<ll,ll>> in(n);
        for (auto &p : in) cin >> p.first >> p.second;

        map<ll,ll> vert, hor, plus, minus;
        for (int i=0; i<n; i++){
            auto p = in[i];
            vert[p.first]++;
            hor[p.second]++;
            plus[p.first-p.second]++;
            minus[p.first+p.second]++;
        }
        ll out = 0;
        for (auto &[k,v]:vert){ out += v * (v-1); }
        for (auto &[k,v]:hor){ out += v * (v-1); }
        for (auto &[k,v]:plus){ out += v * (v-1); }
        for (auto &[k,v]:minus){ out += v * (v-1); }
        cout << out << '\n';
    }

    return 0;
}
