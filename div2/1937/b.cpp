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

vector<string> in;

int main()
{
    in.resize(2);
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        cin >> in[0];
        cin >> in[1];

        string p;
        int lin = 0;
        int idx = n-1;
        for(int i=0; i<n; i++){
            p.push_back(in[lin][i]);
            if (lin == 0 && i+1 < n && in[0][i+1] == '1' && in[1][i] == '0'){
                idx = i;
                lin = 1;
                i--;
            }
        }
        if (p.size() == n) p.push_back(in[1][n-1]);


        int cnt = 0;
        int i = 0;
        int aux = (n-1) - idx;
        while(idx-i >= 0 && n-i >= 0 && in[1][idx-i] == p[n-i-aux]){
            cnt++;
            i++;
        }
        cout << p << '\n';
        cout << cnt << '\n';
    }

    return 0;
}
