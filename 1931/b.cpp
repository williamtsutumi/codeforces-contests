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
        for(int i=0; i<n; i++) cin >> in[i];

        ll tot = 0;
        for(int i=0; i<n; i++){
            tot += in[i];
        }
        ll per = tot / n;

        ll sum = 0;
        bool ok = true;
        for(int i=0; i<n; i++){
            sum += in[i];

            if (sum < per * (i+1)){
                ok = false;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
        

    return 0;
}
