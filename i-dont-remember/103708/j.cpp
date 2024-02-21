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

vector<vector<int>> g;

int main()
{
    int buyers, comp; cin >> buyers >> comp;
    g.resize(200000);
    for(int i=0; i<buyers; i++){
        int a; cin >> a;
        for(int j=0; j<a; j++){
            int b; cin >> b;
            b += 10000;
            g[i].push_back(b);
            g[b].push_back(i);
        }
    }

    return 0;
}