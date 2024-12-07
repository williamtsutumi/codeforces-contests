#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long double ld;
typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

ll dp[25][2];
int n;
vector<ll> vet;

ll solve(ll pile1, ll pile2, int i){
    if(i >= vet.size()) return abs(pile1 - pile2);

    ll p1 = solve(pile1 + vet[i], pile2, i + 1);
    ll p2 = solve(pile1, vet[i] + pile2, i + 1);

    return min(p1, p2);
}

int main()
{
    FFIO;
    memset(dp, -1, sizeof dp);

    cin >> n;
    vet.resize(n);
    for (int i=0; i<n; i++) cin >> vet[i];

    map<int,int> mp;
    for(int i=0; i<n; i++){ mp[vet[i]]++; }
    vet.clear();
    for(auto &[k,v]:mp){
        if (v % 2 == 1) vet.push_back(k);
    }


    cout << solve(0, 0, 0) << endl;


    return 0;
}
