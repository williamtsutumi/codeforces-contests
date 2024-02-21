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
        vector<string> in(8);
        for(int i=0; i<8; i++){ cin >> in[i]; }

        for(int i=1; i<7; i++){
            for(int j=1; j<7; j++){
                if(in[i-1][j-1] == '#'
                        && in[i-1][j+1] == '#'
                        && in[i+1][j-1] == '#'
                        && in[i+1][j+1] == '#'){
                    cout << i+1 << ' ' << j+1 << '\n';
                }
            }
        }
    }

    return 0;
}
