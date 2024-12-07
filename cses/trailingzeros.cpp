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
    int n; cin >> n;
    ll output = 0;
    while(n > 0){
        output += n/5;
        n/=5;
    }
    cout << output << endl;

    return 0;
}
