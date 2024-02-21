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

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        vector<pair<ll , string>> v(n);
        for (int i=0; i<n; i++){
            ll time; cin >> time;
            string in; cin >> in;
            v[i] = {time, in};
        }

        ll both, frst, scnd;
        both = frst = scnd = INT_MAX;
        for (int i=0; i<n; i++){
            if (v[i].second == "11"){
                both = min(v[i].first, both);
            }
            else if (v[i].second == "10"){
                frst = min(frst, v[i].first);
            }
            else if (v[i].second == "01"){
                scnd = min(scnd, v[i].first);
            }
        }
        
        ll out = min(both, frst + scnd);
        if (out >= INT_MAX) cout << -1 << '\n';
        else cout << out << '\n';
    }

    return 0;
}
