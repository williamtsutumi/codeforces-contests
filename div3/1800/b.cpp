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
        int n, k; cin >> n >> k;
        string in; cin >> in;

        map<int,int> mp;
        for(int i=0; i<n; i++) mp[in[i]]++;

        int out = 0;
        for(char c='a'; c<='z'; c++){
            int v = min(mp[c], mp[toupper(c)]);

            out += v;
            mp[c] -= v;
            mp[toupper(c)] -= v;
        }

        int plus = 0;
        for(char c='a'; c<='z'; c++){
            plus += (mp[c] + mp[toupper(c)]) / 2;
        }
        cout << out + min(plus, k) << '\n';
    }

    return 0;
}
