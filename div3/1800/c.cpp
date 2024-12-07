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
        vector<pair<int,int>> in(n);
        for(int i=0; i<n; i++){
            int v; cin >> v;
            in[i] = {v, i};
        }

        set<int> zeros;
        for(int i=0; i<n; i++) if (in[i].first == 0) zeros.insert(i);

        sort(in.begin(), in.end(), greater());

        ll out = 0;
        for(int i=0; i<n; i++){
            int idx = in[i].second;
            auto lb = zeros.upper_bound(idx);
            if (lb != zeros.end() && *lb > idx){
                zeros.erase(lb);
                out += in[i].first;
                if (zeros.size() == 0) break;
            }
        }
        cout << out << '\n';
    }

    return 0;
}
