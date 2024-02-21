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
        if (n > 52){
            cout << (char)(n-53+'a') << 'z' << 'z' << '\n';
        }
        else if (n > 27){
            cout << 'a' << (char)(n-28+'a') << 'z' << '\n';
        }
        else {
            cout << 'a' << 'a' << (char)(n+'a'-3) << '\n';
        }
        
    }

    return 0;
}
