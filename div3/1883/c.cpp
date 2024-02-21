#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int main()
{
    int runs; cin >> runs;
    while (runs--){
        int size, k; cin >> size >> k;

        vector<int> inp(size);
        for (int i=0; i<size; i++) cin >> inp[i];

        int mx = -1;
        int mn = INT32_MAX;
        int odds = 0;
        int even = 0;
        for (int i=0; i<size; i++){
            mx = max(mx, inp[i] % k);
            mn = min(mn, inp[i] % k);
            if (inp[i] % 2 == 1) odds++;
            else even++;
        }
        if (mn == 0){
            cout << 0 << '\n';
            continue;
        }

        if (k == 4){
            if (even >= 2) cout << 0 << '\n';
            else if (even >= 1) cout << 1 << '\n';
            else{
                if (odds >= 2) cout << min(2, k - mx) << '\n';
            }
        }
        else
            cout << k - mx << '\n';
    }

    return 0;
}