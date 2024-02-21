#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const double INF = 1e9 + 7;

int dp[200001];
int dist[200001];
int visited[200001];

void bfs(vector<vector<int>> &vet){
    queue<int> q;
    q.push(0);
    visited[0] = true;
    dist[0] = 0;
    while(!q.empty()){
        int top = q.front();
        // debug(vet);
        q.pop();
        for(int i=0; i<vet[top].size(); i++){
            int elem = vet[top][i];
            if (!visited[elem]){
                visited[elem] = true;
                q.push(elem);
                dist[elem] = dist[top] + 1;
            }
        }
    }
}

ll solve(vector<vector<int>> &vet, int a){
    if (dp[a] != -1) return dp[a];
    if (a != 0 && vet[a].size() == 1) return 1;
    
    ll output = 0;
    for(int i=0; i<vet[a].size(); i++){
        if (dist[vet[a][i]] > dist[a])
            output += solve(vet, vet[a][i]);
    }
    dp[a] = output;
    return dp[a];
}

int main()
{
    int runs; cin >> runs;
    while(runs--){
        int v; cin >> v;
        vector<vector<int>> vet(v);
        for(int i=1; i<v; i++){
            int a,b; cin >> a >> b;
            a--; b--;
            vet[a].push_back(b);
            vet[b].push_back(a);
        }
        memset(visited, false, sizeof(visited));
        memset(dist, 0, sizeof(dist));
        memset(dp, -1, sizeof(dp));
        bfs(vet);
        // for(int i=0; i<v; i++){
        //     debug(dist[i]);
        // }
        // debug(vet);
        int ass; cin >> ass;
        for(int i=0; i<ass; i++){
            int a,b; cin >> a >> b;
            a--; b--;
            
            // debug(solve(vet, a));
            // debug(solve(vet, b));
            cout << solve(vet, a) * solve(vet, b) << endl;
        }

    }

    return 0;
}