#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        string in; cin >> in;

        map<int,int> mp;
        for (int i=0; i<in.size();i++){
            mp[in[i]]++;
        }

        ll out = 0;
        for (auto &[k,v]:mp){
            if (v >= k - 'A' + 1) out++;
        }
        cout << out << endl;
    }

    return 0;
}
