#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const double INF = 1e9 + 7;

int dist[2][1005][1005];

void bfs(pair<int,int> inicio, int lin, int col, int idx){
    dist[idx][inicio.first][inicio.second] = 0;

    queue<pair<int,int>> q;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    q.push(inicio);
    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            pair<int,int> adj = { inicio.first + dx[i], inicio.second + dy[i] };
            if (0 <= adj.first && adj.first < lin && 0 <= adj.second && adj.second <= col){
                if (dist[idx][adj.first][adj.second] == INF){
                    dist[idx][adj.first][adj.second] = dist[idx][u.first][u.second] + 1;
                    q.push(adj);
                }
            }
        }
    }
}

int main()
{
    int lin, col; cin >> lin >> col;
    vector<vector<char>> vet(lin);
    for(int i=0; i<lin; i++){
        string in; cin >> in;
        for(int j=0; j<col; j++){
            vet[i][j] = in[j];
        }
    }
    memset(dist, INF, sizeof(dist));
    bfs({0,0}, lin, col, 0);
    bfs({lin-1,col-1}, lin, col, 1);
    
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            if (dist[0][i][j] + dist[1][i][j] == dist[0][lin-1][col-1])
                cout << "+";
            else
                cout << "-";
        }
        cout << endl;
    }


    return 0;
}