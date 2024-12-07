#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long double ld;
typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

vector<vector<int>> graph;
bool visited[200000];

int dfs(int start){
    if (visited[start]) return 0;
    visited[start] = true;

    stack<int> stk;
    stk.push(start);
    int cnt = 1;
    while(!stk.empty()){
        int top = stk.top();
        stk.pop();
        for(int i=0; i<graph[top].size(); i++){
            int v = graph[top][i];
            if (visited[v]) continue;
            visited[v] = true;

            cnt++;
            stk.push(v);
        }
    }
    return cnt;
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        memset(visited, false, sizeof visited);
        int n; cin >> n;
        graph.clear();
        graph.resize(n);
        map<int, int> mp;
        for(int i=0; i<n; i++){
            int from, to; cin >> from >> to;
            from--; to--;
            mp[from]++;
            mp[to]++;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        bool ok = true;
        for(auto &[k,v]:mp) if (v > 2) ok = false;

        for(int i=0; i<n; i++){
            int r = dfs(i);
            if (r % 2 == 1){
                ok = false;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
