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
        int n, q; cin >> n >> q;
        vector<int> in(n);
        for(int i=0; i<n; i++) cin >> in[i];

        set<int> st;
        for(int i=0; i<n; i++) st.insert(in[i]);

        map<int,int> mpmin, mpmax;
        for(int i=0; i<n; i++){
            mpmax[in[i]] = i;
            if (mpmin.find(in[i]) == mpmin.end()) mpmin[in[i]] = i;
        }

        for(int i=0; i<q; i++){
            int from, to; cin >> from >> to;
            if (st.find(from) == st.end() || st.find(to) == st.end()){
                cout << "NO\n";
                continue;
            }

            if (mpmin[from] < mpmax[to]) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
