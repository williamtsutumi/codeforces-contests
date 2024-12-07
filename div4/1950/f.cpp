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
        int a, b, c; cin >> a >> b >> c;
        if (a+b+c != 2*a + b + 1){
            cout << -1 << '\n';
            continue;
        }
        int sla = 1;
        int out = 0;
        while (sla < a){ sla *= 2; out++; }

        int spaces = sla - (a -(sla-1));
        if (b > 0) out++;
        if (b > spaces) out++;
        cout << out << '\n';
    }

    return 0;
}
