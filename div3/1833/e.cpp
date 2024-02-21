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

int dfs(vector<set<int>> &g){
    bool visited[g.size()];
    memset(visited, false, sizeof(visited));
    int top = 0;
    stack<int> stk;
    int cnt = 0;
    int idx = 0;
    for (int i=0; i<g.size(); i++){
        if (visited[i]) continue;
        cnt++;

        top = i;
        stk.push(top);
        visited[top] = true;

        while (!stk.empty()){
            top = stk.top();
            stk.pop();
            for (auto it=g[top].begin(); it != g[top].end(); it++){
                int v = *it;
                if (visited[v]) continue;
                visited[v] = true;

                stk.push(v);
            }
        }
    }
    return cnt;
}

int main()
{
    FFIO;
    int r; cin >> r;
    while (r--){
        int n; cin >> n;

        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
            v[i]--;
        }
        vector<set<int>> g(n);
        for (int i=0; i<n; i++){
            g[i].insert(v[i]);
            g[v[i]].insert(i);
        }
        int cnt = 0;
        for (int i=0; i<n; i++){
            if (g[i].size() == 1) cnt++;
        }
        int mx = dfs(g);
        int mn = mx - (cnt/2) + 1;
        mn = min(mn, mx);
        cout << mn << ' ' << mx << '\n';
    }

    return 0;
}
