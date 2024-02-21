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

struct DSU{

  int n;
  vector<int> parent, sz;

  DSU(int n) : parent(n), sz(n) {
    for(int i = 0; i < n; i++) parent[i] = i;
    this->n = n;
  };

  void make(int n){
    for(int i = 0; i < n; i++) parent[i] = i, sz[i] = 1;
  }

  int find(int v){
    return parent[v] == v ? v : (parent[v] = find(parent[v]));
  }

  void onion(int u, int v){
    u = find(u), v = find(v);
    if(u == v) return;

    if(sz[u] > sz[v]) swap(u, v);

    parent[u] = v;
    sz[v] += sz[u];
  }
};


vector<vector<int>> graph;
vector<int> anc;
int distance[200001];
bool visited[200001];

pair<int,int> bfs(){
    int first = 1;
    queue<int> q;
    q.push(first);
    visited[first] = true;
    distance[first] = 0;

    pair<int,int> out;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(int i=0; i<graph[top].size(); i++){
            int u = graph[top][i];
            if(visited[u]) continue;
            visited[u] = true;
            q.push(u);

            distance[u] = h[top] + 1;
            anc[u] = top;

            if(distance[u] > out.second){
                out.first = {u, distance[u]};
            }
        }
    }

    return out;
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int v, dst, cost; cin >> v >> dst >> cost;
        graph.assign(v+1, {});
        anc.assign(v+1, {});
        for(int i=1; i<v; i++){
            int from, to; cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        DSU dsu(v+1);

        memset(h, -1, sizeof(h));
        memset(visited, false, sizeof(visited));

        auto s = solve();
        int curr = s.first;
        int st = curr;
        while(anc[curr] != 1){
            st = curr;
            dsu.onion(curr, anc[curr]);
            curr = anc[curr];
        }

        for(int i=1; i<=v; i++){

        }
    }

    return 0;
}
