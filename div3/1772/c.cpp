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
        int max, n; cin >> n >> max;

        int aux = 0;
        for(int i=1, cnt=0; cnt<n; cnt++, i++){
            int left = n-cnt;
            int ican = max-cnt;
            // the amount left after writing (i+aux) must be >= left
            // max - (i+aux) >= n-cnt
            if (max - (i + aux)+1 >= n-cnt){
                cout << i + aux << ' ';
                aux++;
                i += aux-1;
            }
            else{
                cout << i << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
