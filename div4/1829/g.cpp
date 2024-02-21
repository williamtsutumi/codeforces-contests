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
    ll pref[1500][1500];
    ll output[2000001];
    ll curr = 1;
    for (int i=1; i<1500; i++){
        int aux = i;
        int col = 1;
        while (aux > 0){
            pref[aux][col] = pref[aux-1][col] + pref[aux][col-1] - pref[aux-1][col-1] + curr * curr;
            output[curr] = pref[aux][col];
            col++;
            curr++;
            aux--;
        }
    }

    while(r--){
        ll n; cin >> n;

        cout << output[n] << '\n';
    }

    return 0;
}
