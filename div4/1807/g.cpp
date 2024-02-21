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

bool solve(vector<ll> &in){
    if (in[0] > 1) return false;

    vector<ll> sums(in.size());
    sums[0] = in[0];
    for (int i=1; i<in.size(); i++){
        sums[i] = sums[i-1] + in[i];
    }
    bool ok = true;
    for (int i=1; i<in.size(); i++){
        if (in[i] > sums[i-1]){
            ok = false;
            break;
        }
    }
    return ok;

}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        ll n; cin >> n;
        vector<ll> in(n);
        for (int i=0; i<n; i++) cin >> in[i];

        sort(in.begin(), in.end());

        bool ans = solve(in);
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
