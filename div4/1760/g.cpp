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

ll v, start, eend;
vector<ll> path;
vector<ll> calc;

void dfs(vector<vector<pair<ll, ll>>> &graph){
    stack<ll> stk;
    stk.push(start);
    calc[start] = 0;

    bool visited[v];
    memset(visited, false, sizeof(visited));
    visited[start] = true;

    while (!stk.empty()){
        ll top = stk.top();
        stk.pop();

        for (int i=0; i<graph[top].size(); i++){
            ll u = graph[top][i].first;
            if (visited[u]) continue;

            visited[u] = true;
            path[u] = top;
            calc[u] = calc[top] ^ graph[top][i].second;
            if (u != eend) stk.push(u);
        }
    }
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        cin >> v >> start >> eend;
        start--; eend--;

        vector<vector<pair<ll, ll>>> graph(v);
        path.assign(v, -1);
        calc.assign(v, 0);

        for (int i=0; i<v-1; i++){
            ll from, to, w; cin >> from >> to >> w;
            from--; to--;
            graph[from].push_back({to, w});
            graph[to].push_back({from, w});
        }
        dfs(graph);

        set<ll> st;
        for (int i=0; i<v; i++){
            if (i == eend) continue;
            if (i == start) continue;
            if (calc[i] == -1) continue;

            st.insert(calc[i]);
        }
        debug(path);
        debug(calc);
        ll curr = start;
        bool ok = false;
        while (path[curr] != -1){
            ll val = calc[curr];
            if (val == 0 || st.contains(val)){
                ok = true;
                break;
            }
            curr = path[curr];
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
