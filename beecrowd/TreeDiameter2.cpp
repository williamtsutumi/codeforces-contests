#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PER(i, a, b) for (int i = a; i >= b; i--)
#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
const double INF = 1e9 + 7;

vector<vi> graph;
int dist[200000];

int bfs(int node)
{
    memset(dist, -1, sizeof(int) * 2e5);
    dist[node] = 0;

    int max_dist = 0, out_node = node;

    queue<int> q;
    q.push(node);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (int adj : graph[front])
        {
            if (dist[adj] != -1)
                continue;
            
            dist[adj] = dist[front] + 1;
            q.push(adj);

            if (dist[adj] > max_dist)
                max_dist = dist[adj], out_node = adj;
        }
    }
    return out_node;
}

int main()
{
    int nodes; cin >> nodes;
    graph.resize(nodes);
    while (--nodes)
    {
        int from, to; cin >> from >> to;
        graph[from - 1].PB(to - 1);
        graph[to - 1].PB(from - 1);
    }
    int a = bfs(0);
    int b = bfs(a);
    cout << dist[b] << endl;

    return 0;
}