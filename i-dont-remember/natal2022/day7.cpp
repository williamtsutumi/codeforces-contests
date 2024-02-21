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

map<string, vector<string>> graph;
map<string, ll> weight;
vector<ll> results;
map<string, bool> visited;

ll solve(string s){
    ll out = weight[s];

    queue<string> q;
    q.push(s);
    while (!q.empty()){
        string curr = q.front();
        q.pop();
        if (visited[curr]) continue;
        visited[curr] = true;

        for (int i=0; i<graph[curr].size(); i++){
            q.push(graph[curr][i]);
            out += weight[curr];
        }
    }
    results.push_back(out);
    return out;
}


int main()
{
    map<string, string> ancestor;
    string in;
    string current_dir;
    bool read = true;
    while (1){
        if (read) cin >> in;
        debug(in);
        read = true;
        if (in == "$"){
            cin >> in;
            debug(in);
            if (in == "cd"){
                cin >> in;
                debug(in);
                if (in == ".."){
                    current_dir = ancestor[current_dir];
                }
                else{
                    current_dir = in;
                }
            }
            else if (in == "ls"){
                while (1){
                    if (!(cin >> in) || in == "$"){
                        debug(in);
                        read = false;
                        break;
                    }
                    if (in == "dir"){
                        cin >> in;
                        debug(in);
                        ancestor[in] = current_dir;
                        graph[current_dir].push_back(in);
                    }
                    else{
                        weight[current_dir] += stoi(in);
                        cin >> in;
                        debug(in);
                    }
                }
            }
        }
        else{
            cout << "Ultimo char lido: " << in << endl;
            break;
        }
    }
    for (auto [k,v]:graph){
        debug(k, v);
    }
    for (auto [k,v]:weight){
        debug(k, v);
    }
    cout << "chegou aqui" << endl;

    ll output = 0;
    for (auto [k,v] : graph){
        if (solve(k) <= 100000) output += solve(k);
    }
    debug(output);

    return 0;
}
