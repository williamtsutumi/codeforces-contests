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

        for(int j=0; j<n; j++){
            for(int i=0; i<n; i++){
                if ((i+j) % 2 == 0) cout << "##";
                else cout << "..";
            }
            cout << '\n';
            for(int i=0; i<n; i++){
                if ((i+j) % 2 == 0) cout << "##";
                else cout << "..";
            }
            cout << '\n';
        }
    }

    return 0;
}
