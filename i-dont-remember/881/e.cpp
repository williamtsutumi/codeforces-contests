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
    int runs; cin >> runs;
    while(runs--){
        int n, seg; cin >> n >> seg;
        vector<pair<int,int>> segs(seg);
        for(int i=0; i<seg; i++){
            int a,b; cin >> a >> b;
            segs[i] = {a,b};
        }
        int x; cin >> x;
        vector<int> vet(x);
        for(int i=0; i<x; i++){
            cin >> vet[i];
        }
        // debug(segs);
        // debug(vet);
        auto solve = [&](int n) -> bool {
            n++;
            vector<int> ones(seg);
            for(int i=0; i<n; i++){
                for(int j=0; j<seg; j++){
                    if (segs[j].first <= vet[i] && vet[i] <= segs[j].second){
                        ones[j]++;
                    }
                }
            }
            for(int i=0; i<seg; i++){
                int aux = ceil((segs[i].second - segs[i].first+1)/2)+1;
                if (ones[i] >= aux)
                    return true;
            }
            return false;
        };
        int mn = 0;
        int mx = x;
        bool ok = true;
        while(mn <= mx){
            if (mn+1 > x){
                cout << -1 << endl;
                ok = false;
            }
            int mid = (mn + mx) / 2;

            if (solve(mid)){
                mx = mid-1;
            } else {
                mn = mid+1;
            }
        }
        if (ok) cout << mn+1 << endl;
    }

    return 0;
}