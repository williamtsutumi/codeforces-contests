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

int lins, cols;
vector<vector<int>> in;

ll solve(int i, int j){
    ll out = in[i][j];
    for(int a=1; a+i < lins && a+j < cols; a++){ out += in[i+a][j+a]; }
    for(int a=1; i-a >= 0 && a+j < cols; a++){ out += in[i-a][j+a]; }
    for(int a=1; a+i < lins && j-a >= 0; a++){ out += in[i+a][j-a]; }
    for(int a=1; i-a >= 0 && j-a >= 0; a++){ out += in[i-a][j-a]; }
    return out;
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        cin >> lins >> cols;

        in.resize(lins);
        for(int i=0; i<lins; i++){
            in[i].resize(cols);
            for(int j=0; j<cols; j++){
                int a; cin >> a;
                in[i][j] = a;
            }
        }

        ll mx = 0;
        for(int i=0; i<lins; i++){
            for(int j=0; j<cols; j++){
                mx = max(mx, solve(i,j));
            }
        }
        cout << mx << '\n';
    }

    return 0;
}
