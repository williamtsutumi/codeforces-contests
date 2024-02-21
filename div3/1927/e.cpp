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
    /*
     * n = 6, k = 3
     * 1 4 5 2 3 6
     *
     * a b c ... a+1 b-1 c+1.
     *
     * n = 5, k = 3
     * 1 4 5 2 3
     * 
     */
    int r; cin >> r;
    while(r--){
        int n, k; cin >> n >> k;
        k = n/2;
        vector<int> v(n);
        v[0] = 1;
        for(int i=1; i<k; i++){
            if (i%2 == 0) v[i] = v[i-1] + 1;
            else v[i] = v[i-1] + 3;
        }
        for(int i=k; i<n; i++){
            if (i%2 == 0) v[i] = v[i-k] + 1;
            else v[i] = v[i-k] - 1;
        }

        for(int i=0; i<n/2; i++){
            cout << v[i] << ' ';
        }
        if (n % 2 == 1) cout << n << ' ';
        for(int i=n/2; i<v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
