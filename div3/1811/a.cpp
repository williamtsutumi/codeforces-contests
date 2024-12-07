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
        int n, d; cin >> n >> d;
        string in; cin >> in;

        int idx = n;
        if (in[0]-'0' < d){
            idx = 0;
        }
        else{
            for(int i=0; i<n-1; i++){
                char c = in[i]-'0';
                if (c >= d && in[i+1]-'0' < d){
                    idx = i+1;
                    break;
                }
            }
        }

        for(int i=0; i<idx; i++){
            cout << in[i] -'0';
        }
        cout << d;
        for(int i=idx; i<n; i++) cout << in[i] -'0';

        cout << '\n';
    }

    return 0;
}
