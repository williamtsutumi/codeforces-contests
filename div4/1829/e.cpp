#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long double ld;
typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

vector<ll> sz;
bool visited[1000][1000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int lines, cols;

void visit(vector<vector<int>> &in, pair<int,int> s){
    if (visited[s.first][s.second]) return;

    ll sum = 0;
    stack<pair<int,int>> stk;
    stk.push({s.first,s.second});
    visited[s.first][s.second] = true;
    while (!stk.empty()){
        auto top = stk.top();
        stk.pop();

        sum += in[top.first][top.second];
        for (int i=0; i<4; i++){
            pair<int,int> v = {top.first+dx[i], top.second+dy[i]};
            v.first = min(lines-1, v.first);
            v.first = max(0, v.first);
            v.second = min(cols-1, v.second);
            v.second = max(0, v.second);
            if (visited[v.first][v.second]) continue;
            visited[v.first][v.second] = true;
            if (in[v.first][v.second] == 0) continue;
            stk.push(v);
        }
    }
    sz.push_back(sum);
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        sz.clear();
        cin >> lines >> cols;

        vector<vector<int>> in(lines);
        for (int i=0; i<lines; i++){
            for (int j=0; j<cols; j++){
                int a; cin >> a;
                in[i].push_back(a);
            }
        }

        memset(visited, false, sizeof(visited));

        for (int i=0; i<lines; i++){
            for (int j=0; j<cols; j++){
                visit(in, {i,j});
            }
        }
        ll mx = INT_MIN;
        for (int i=0; i<sz.size(); i++){
            mx = max(mx, sz[i]);
        }
        cout << mx << '\n';
    }

    return 0;
}
