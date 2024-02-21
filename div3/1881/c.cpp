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

int main()
{
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        vector<string> in(n);
        for(int i=0;i<n;i++)cin>>in[i];

        int out = 0;
        for(int i=0; i<n/2; i++){
            int aux = (n-i-1);
            for (int j=0; j<n-i*2-1; j++){
                int mx = max({in[i+j][i], in[i][aux-j], in[aux-j][aux], in[aux][i+j]});
                out += mx - in[i+j][i] + mx - in[i][aux-j] + mx - in[aux-j][aux] + mx - in[aux][i+j];
            }
        }
        cout << out << '\n';
    }

    return 0;
}
