#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
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

vector<vector<int>> graph;
int sz[200000];

int calc(int v){
    if (sz[v] != -1) return sz[v];
    int out = 1;
    for (auto u : graph[v]){
        out += calc(u);
    }
    sz[v] = out;
    return out;
}

int solve(int v, int k){
    int mx = -1;
    int tot = 0;
    for (int u : graph[v]){
        if (mx == -1 || sz[u] > sz[mx]) mx = u;
        tot += sz[u];
    }

    if (tot == 0) return 0;
    if (sz[mx]-k <= tot - sz[mx]) return (tot-k) / 2;
    int out = tot - sz[mx];
    return out + solve(mx, max(0, k+out-1));
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        graph.clear();
        graph.resize(n);
        for(int i=1; i<n; i++){
            int v; cin >> v;
            graph[v-1].push_back(i);
        }

        memset(sz, -1, sizeof(sz));
        calc(0);
        cout << solve(0,0) << '\n';
    }

    return 0;
}
