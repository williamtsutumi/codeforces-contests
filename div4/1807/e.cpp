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
        for (int i=0; i<n; i++) cin >> in[i];

        vector<int> sums(n);
        sums[0] = in[0];
        for(int i=1; i<n; i++) sums[i] = sums[i-1] + in[i];

        int hi = n;
        int lo = 1;
        ll sum;
        while (lo <= hi){
            int mid = (hi + lo) /2;
            cout << "? ";
            for (int i=lo; i<=mid; i++){
                cout << i << ' ';
            }
            cout << "\n";
            cout.flush();
            cout << "\n";

            cin >> sum;
            ll normal = sums[mid-1];
            if (lo-2 >= 0) normal -= sums[lo-2];
            if (sum == normal){
                lo = mid+1;
            }
            else hi = mid-1;
        }
        cout << "! " << lo << "\n\n";
    }

    return 0;
}
