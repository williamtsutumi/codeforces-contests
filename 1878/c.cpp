#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
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
    FFIO;
    int r; cin >> r;
    while(r--){
        ll n, k, sum; cin >> n >> k >> sum;

        ll mn = ((1 + k) * k) / 2;
        ll mx = ((n + (n-k+1)) * k) / 2;
        if (mn <= sum && sum <= mx) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
