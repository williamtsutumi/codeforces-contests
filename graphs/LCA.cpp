#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double
#define X real()
#define Y imag()

typedef long long C;
typedef complex<C> P;
typedef long long ll;
const double INF = 1e9 + 7;

int lca(int a, int b, vector<int> &parent, vector<int> &rank){
    // debug2(rank[a], rank[b])
    if (rank[a] < rank[b]) swap(a,b);
    // debug2(a,b)

    int parentA = parent[a];
    while (rank[parentA] > rank[b]){
        parentA = parent[parentA];
    }
    // debug2(parentA, b)
    while(1){
        // debug(a)
        if (parentA == parent[b]) return parent[b];
        if (b == -1 || parentA == -1) return 0;
        parentA = parent[parentA];
        b = parent[b];
    }
}

int main()
{
    int runs; cin >> runs;
    for(int aux=1; aux<=runs; aux++){
        int vertices; cin >> vertices;
        vector<int> parent(vertices);
        vector<int> rank(vertices);
        rank[0] = 1;
        parent[0] = -1;
        for(int i=0; i<vertices; i++){
            int childs; cin >> childs;
            for (int j=0; j<childs; j++){
                int c; cin >> c;
                c--;
                parent[c] = i;
                rank[c] = rank[i] + 1;
            }
        }
        // for (int i=0; i<vertices; i++){
        //     debug(parent[i])
        //     debug(rank[i])
        // }
        int pairs; cin >> pairs;
        cout << "Case " << aux << ":" << endl;
        for(int i=0; i<pairs; i++){
            int a,b; cin >> a >> b;
            a--; b--;
            cout << lca(a,b, parent, rank) + 1 << endl;
        }
    }

    return 0;
}