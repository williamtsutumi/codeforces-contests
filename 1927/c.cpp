#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long double ld;
typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n, m, k; cin >> n >> m >> k;
        set<int> a, b;
        for(int i=0; i<n; i++){
            int v; cin >> v;
            if (v <= k) a.insert(v);
        }
        for(int i=0; i<m; i++){
            int v; cin >> v;
            if (v <= k) b.insert(v);
        }

        bool ok = true;
        for(int i=1; i<=k; i++){
            if (a.find(i) == a.end() && b.find(i) == b.end()) ok = false;
        }
        if (a.size() < k/2 || b.size() < k/2) ok = false;

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
