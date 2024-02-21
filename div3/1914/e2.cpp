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


ll solve(vector<int> &a, vector<int> &b){
    int n = a.size();

    vector<pair<int,int>> maximos(n);
    for (int i=0; i<n; i++){ maximos[i] = {a[i]+b[i], i}; }
    sort(maximos.begin(), maximos.end(), greater<>());

    for (int i=0; i<n; i++){
        int idx = maximos[i].second;
        if (i%2 == 0){
            a[idx]--;
            b[idx] = 0;
        }
        else{
            b[idx]--;
            a[idx] = 0;
        }
    }

    ll out = 0;
    for (int i=0; i<n; i++) out += a[i];
    for (int i=0; i<n; i++) out -= b[i];
    return out;
}

int main()
{
    FFIO;
    int r; cin >> r;
    vector<int> a;
    vector<int> b;
    while(r--){
        int n; cin >> n;
        a.resize(n);
        b.resize(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];

        ll s = solve(a,b);
        cout << s << '\n';
    }

    return 0;
}
