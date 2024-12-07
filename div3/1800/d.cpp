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
        string in; cin >> in;

        int cnt = 0;
        for(int i=2; i<n; i++){
            if (in[i-2] == in[i]) cnt++;
        }

        cout << n -1 - cnt << '\n';
    }

    return 0;
}
