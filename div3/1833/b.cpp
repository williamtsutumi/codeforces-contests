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
        int n, k; cin >> n >> k;

        vector<pair<int,int>> v(n);
        for (int i=0; i<n; i++){
            int a; cin >> a;
            v[i] = {a, i};
        }

        vector<int> temp(n);
        for (int i=0; i<n; i++) cin >> temp[i];

        sort(temp.begin(), temp.end());
        sort(v.begin(), v.end());

        vector<int> out(n);
        for (int i=0; i<n; i++){
            out[v[i].second] = temp[i];
        }
        for (int i=0; i<n; i++){
            cout << out[i] << ' ';
        }
        cout << endl;

    }

    return 0;
}
