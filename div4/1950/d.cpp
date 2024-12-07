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

bool dp[100002];

void comp(int n){
    if (n >= 100001) return;
    dp[n] = true;

    comp(n*10);
    comp(n*11);
    comp(n*100);
    comp(n*101);
    comp(n*110);
    comp(n*111);
    comp(n*1000);
    comp(n*1001);
    comp(n*1010);
    comp(n*1011);
    comp(n*1100);
    comp(n*1101);
    comp(n*1110);
    comp(n*1111);
    comp(n*10000);
    comp(n*10001);
    comp(n*10010);
    comp(n*10011);
    comp(n*10100);
    comp(n*10101);
    comp(n*10110);
    comp(n*10111);
    comp(n*11000);
    comp(n*11001);
    comp(n*11010);
    comp(n*11011);
    comp(n*11100);
    comp(n*11101);
    comp(n*11110);
    comp(n*11111);
    comp(n*100000);
}

int main()
{
    memset(dp, false, sizeof dp);
    dp[0] = true;
    comp(1);

    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        if (dp[n]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
