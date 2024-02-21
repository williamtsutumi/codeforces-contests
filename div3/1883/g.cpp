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
    while(runs--){
        int n, k; cin >> n >> k;

        vector<int> vet1(n);
        vet1[0] = 1;
        vector<int> vet2(n);
        for (int i=1; i<n; i++) cin >> vet1[i];
        for (int i=0; i<n; i++) cin >> vet2[i];

        sort(vet1.begin(), vet1.end());
        sort(vet2.begin(), vet2.end());
        // debug(vet1);
        // debug(vet2);
        int idx1 = 0;
        int idx2 = 0;
        int ans = 0;
        for (int i=0; i<n && idx1 < n-ans; i++){
            // debug(idx1, idx2, ans);
            if (vet1[idx1] < vet2[idx2]){
                idx1++;
                idx2++;
            }
            else{
                ans++;
                idx2++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
