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
        vector<int> in(n);
        for(int i=0; i<n; i++) cin >> in[i];

        ll sum = 0;
        bool ok1 = false;
        bool ok2 = false;
        for(int i=0; i<n; i++){
            sum += in[i];
            if (in[i] % 3 == 1) ok1 = true;
            if (in[i] % 3 == 2) ok2 = true;
        }
        if (sum % 3 == 0) cout << 0 << '\n';
        else if (sum % 3 == 1){
            if (ok1) cout << 1 << '\n';
            else cout << 2 << '\n';
        }
        else{
            cout << 1 << '\n';
        }
    }


    return 0;
}
