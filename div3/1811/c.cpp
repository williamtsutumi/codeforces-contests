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
        n--;
        vector<int> in(n);
        for(int i=0; i<n; i++) cin >> in[i];

        vector<int> out(n+1);
        out[0] = 0;
        out[1] = in[0];
        for(int i=1; i<n; i++){
            if (in[i] < in[i-1]){
                out[i-1] = in[i-1];
                out[i] = 0;
                out[i+1] = in[i];
            }
            else{
                out[i+1] = max(in[i], in[i-1]);
            }
        }
        for(int i=0; i<n+1; i++){
            cout << out[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
