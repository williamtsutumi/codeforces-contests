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
    /*
     * n = 10
     * 1 3 5 7 9 -> 2 6 10 -> 9 -> 4
     * all odd (places ceil(n/2) numbers)
     * -> all n % 2 == 0 and n/2 % 2 == 1 (places floor(n/3) numbers)
     * -> all n % 3 == 0 and n/3 % 2 == 1 (places floor(n/4) numbers)
     * -> all n % 4 == 0 and n/4 % 2 == 1
     *
     * n = 7
     * 1 3 5 7 -> 2 6 -> 4
     */
    FFIO;
    int r; cin >> r;
    while(r--){
        int n, k; cin >> n >> k;

        ll curr = 2;
        ll sum = ceil(n/2.0);
        ll prev = 0;
        while (sum < k){
            prev = sum;
            curr++;
            if (sum == n-1) sum++;
            else sum += max((ll)1, n/curr);

        }

        ll aux = k - prev-1;
        curr--;
        debug(curr, aux);
        cout << + aux*(2*curr) << endl;
    }

    return 0;
}
