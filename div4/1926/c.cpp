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

int dp[200003];



int main()
{
    FFIO;

    dp[1] = 1;
    for(int i=2; i<=200000; i++){
        string str = to_string(i);
        int curr = 0;
        for(int j=0; j<str.size(); j++){
            curr += str[j] - '0';
        }
        dp[i] = dp[i-1] + curr;
    }

    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}
