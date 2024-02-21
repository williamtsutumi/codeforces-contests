#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int main()
{
    int r; cin >> r;
    while(r--){
        int a, b, c; cin >> a >> b >> c;

        int mn = min({a,b,c});
        if (a % mn != 0 || b % mn != 0 || c % mn != 0){
            cout << "NO\n";
            continue;
        }
        if (a/mn +b/mn +c/mn > 6){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }

    return 0;
}
