#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
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

vector<string> read(){
    string line;
    vector<string> out;
    while(getline(cin, line)){
        stringstream ss(line);
        string str;
        while(getline(ss, str, ' ')){
            out.push_back(str);
        }
    }
    return out;
}

vector<bool> visited;
vector<int> dist;

void bfs(vector<vector<int>> &graph, int f){
    queue<int> q;
    q.push(f);
    while (!q.empty()){
        int front = q.front();
        q.pop();
        for (int i=0; i<graph[front].size(); i++){
            int v = graph[front][i];
            if(visited[v]) continue;
            visited[v] = true;

            q.push(v);
            dist[v] = dist[front] + 1;
        }
    }
}

int main()
{
    FFIO;
    // if d[cop] > d[thief] then no
    int r; cin >> r;
    while(r--){
        int n, cop, thief; cin >> n >> cop >> thief;
        visited.resize(n);
        dist.resize(n);
        vector<vector<int>> graph(n);
        for(int i=0; i<n; i++){
            int from, to; cin >> from >> to;
            from--; to--;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        int dgThree = -1;
        for (int i=0; i<n; i++){
            if (in[i].size() == 3){
                dgThree = i;
                break;
            }
        }
        if (dgThree == -1){
            cout << "YES\n";
            continue;
        }

        stack<int> s;
        s.push(dfThree);
        bool visit[n];
        memset(visit, false, sizeof(visit));
        bool found = false;
        while (!s.empty()){
            int top = s.top();
            s.pop();
            for (int i=0; i<graph[top].size(); i++){
                int v = graph[top][i];
                if (visit[v]){
                    found = true;
                    break;
                } 

                visit[v] = true;
                s.push(v);
            }
            if (found) break;
        }
        vector<int> v;
        while (!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        bool ok = false;
        for (int i=0; i<v.size(); i++){
            if (thief == v[i]){
                cout << "YES\n";
                ok = true;
                break;
            }
        }
        if (ok) continue;

        bfs(graph, dgThree);

    }

    return 0;
}
