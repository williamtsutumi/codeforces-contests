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

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int v, e; cin >> v >> e;
        vector<vector<int>> graph(v);

        for (int i=0; i<e; i++){
            int from, to; cin >> from >> to;
            from--; to--;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        int start = -1;
        int y = -1;
        int next = -1;
        for (int i=0; i<v; i++){
            if (graph[i].size() == 1){
                int u = graph[i][0];
                y = graph[u].size()-1;
                next = u;
                break;
            }
        }
        int x = y;
        for (int i=0; i<graph[next].size(); i++){
            int u = graph[next][i];
            int sz = graph[u].size();
            if (sz != y && sz != 1){
                x = sz;
                break;
            }
        }
        cout << x << ' ' << y << '\n';
    }

    return 0;
}
