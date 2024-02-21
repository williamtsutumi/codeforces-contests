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

const int N = 200000;
ll positions[N];
bool visited[N];

bool visit(vector<vector<pair<ll,ll>>> &graph){
    stack<int> stk;
    stk.push(0);
    visited[0] = true;
    while(!stk.empty()){
        int top = stk.top();
        stk.pop();
        int its = graph[top].size();
        for (int i=0; i<its; i++){
            int next = graph[top][i].first;
            if (visited[next]){
                if (positions[next] != graph[top][i].second + positions[top]) return false;
                continue;
            } 
            visited[next] = true;
            stk.push(next);
            positions[next] = graph[top][i].second + positions[top];
        }
    }
    return true;
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int soldiers, conditions; cin >> soldiers >> conditions;
        memset(positions, -1, sizeof(positions));
        memset(visited, false, sizeof(visited));
        positions[0] = 0;
        vector<vector<pair<ll,ll>>> graph(soldiers);
        for (int i=0; i<conditions; i++){
            ll from, to, dst; cin >> from >> to >> dst;
            from--; to--;
            graph[from].push_back({to, dst});
            graph[to].push_back({from, -dst});
        }
        auto out = visit(graph);
        if (out) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
