#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const double INF = 1e9 + 7;

ll lis(ll N, vector<ll> v){
    const int MAXN = 1e6+5;
    ll dp[N], n, lis;

    memset(dp, 63, sizeof dp);
    for (ll i = 0; i < n; ++i) {
        // increasing: lower_bound
        // non-decreasing: upper_bound
        ll j = lower_bound(dp, dp + lis, v[i]) - dp;
        dp[j] = min(dp[j], v[i]);
        lis = max(lis, j + 1);
    }
    return lis;
}

int main()
{
    ll tx, ty; cin >> tx >> ty;
    P tv = {tx,ty};
    int points; cin >> points;
    map<P, vector<ll>> mp;
    for(int i=0; i<points; i++){
        ll x,y,h; cin >> x >> y >> h;
        ll gcd = __gcd(x, y);
        mp[{(x-tv.X)/gcd, (y-tv.Y)/gcd}].push_back(h);
    }
    ll output = 0;
    for(auto &[key,val]: mp){
        output += lis(val.size(), val);
    }
    cout << output << endl;

    return 0;
}