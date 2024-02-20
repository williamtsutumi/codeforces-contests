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

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        vector<int> in(n);
        for (int i=0; i<n; i++) cin >> in[i];

        int idx = -1;
        int mx = -1;
        int mx2 = -1;
        for (int i=0; i<n; i++){
            if (in[i] > mx){
                idx = i;
                mx2 = mx;
                mx = in[i];
            }
        }
        for (int i=0; i<n; i++){
            if (i != idx && in[i] > mx2){
                mx2 = in[i];
            }
        }
        for (int i=0; i<n; i++){
            if (i != idx){
                cout << in[i] - mx << ' ';
            }
            else cout << in[i] - mx2 << ' ';
        }
        cout << '\n';
    }

    return 0;
}
