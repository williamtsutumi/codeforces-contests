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
        int n, t; cin >> n >> t;
        vector<int> len(n);
        vector<int> ent(n);
        for(int i=0; i<n; i++) cin >> len[i];
        for(int i=0; i<n; i++) cin >> ent[i];


        int out = -1;
        int mx = -1;
        for(int i=0; i<n; i++){
            if (len[i] + i <= t){
                if (ent[i] > mx){
                    mx = ent[i];
                    out = i+1;
                }
            }
        }
        cout << out << '\n';
    }

    return 0;
}
