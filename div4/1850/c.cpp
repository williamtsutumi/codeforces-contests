#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        vector<string> in(8);
        for (int i=0; i<8; i++) cin >> in[i];

        pair<int,int> p;
        bool ok = false;
        for (int i=0; i<8; i++){
            for (int j=0; j<8; j++){
                if (in[i][j] != '.'){
                    p = {i,j};
                    ok = true;
                    break;
                }
            }
            if (ok) break;
        }

        while(p.first < 8 && in[p.first][p.second] != '.'){
            cout << in[p.first++][p.second];
        }
        cout << '\n';
    }

    return 0;
}
