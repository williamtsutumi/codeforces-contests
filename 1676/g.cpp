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

vector<vector<int>> graph;
vector<char> colors;
int n;

pair<ll, pair<int,int>> solve(int v, int b, int w){
    ll out = 0;
    int its = graph[v].size();
    for(int i=0; i<its; i++){
        int u = graph[v][i];
        auto s = solve(u, 0, 0);
        out += s.first;
        b += s.second.first;
        w += s.second.second;
    }

    if (colors[v] == 'B'){ b++; }
    else{ w++; }
    if (b == w) out++;

    return {out, {b, w}};
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        cin >> n;
        graph.assign(n+1, {});
        for(int i=2; i<=n; i++){
            int v; cin >> v;
            graph[v].push_back(i);
        }

        colors.resize(n+1);
        for(int i=1; i<=n; i++){ cin >> colors[i]; }

        cout << solve(1, 0, 0).first << '\n';
    }

    return 0;
}
