#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
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
const ll INF = 1e9 + 7;

bool visited[200000];
int dist[200000];

void bfs(vector<vector<int>> &graph, int first){
    queue<int> q;
    q.push(first);
    visited[first] = true;
    while (!q.empty()){
        int front = q.front();
        q.pop();
        for (int i=0; i<graph[front].size(); i++){
            int v = graph[front][i];
            if (visited[v]) continue;
            visited[v] = true;

            dist[v] = dist[front] + 1;
            q.push(v);
        }
    }
}

// find the maximum distance betweem two marked vertices
int solve(vector<vector<int>> &graph, vector<bool> &marked){
    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist)); 
    bfs(graph, 0);

    int first = 0;
    for (int i=0; i<graph.size(); i++){
        if (marked[i] && dist[i] > dist[first]){
            first = i;
        }
    }
    
    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist)); 
    bfs(graph, first);

    int out = 0;
    for (int i=0; i<graph.size(); i++){
        if (marked[i]) out = max(out, dist[i]);
    }
    return out;
}

int main()
{
    FFIO
    int r; cin >> r;
    while(r--){
        int v, m; cin >> v >> m;

        vector<bool> marked(v);
        for (int i=0; i<m; i++){
            int a; cin >> a;
            marked[a-1] = true;
        }

        vector<vector<int>> graph(v);
        for (int i=0; i<v-1; i++){
            int from, to; cin >> from >> to;
            graph[from-1].push_back(to-1);
            graph[to-1].push_back(from-1);
        }

        int s = solve(graph, marked);
        s = s / 2 + (int)(s % 2 != 0);
        cout << s << '\n';
    }

    return 0;
}
