#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../debug.h"
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
        int a, b; cin >> a >> b;
        if((a+b) % 3 != 0 || (abs(a-b) > (a+b)/3)) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}
