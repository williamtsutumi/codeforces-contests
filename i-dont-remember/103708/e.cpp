#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

ll comb( ll n, ll k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    ll result = n;
    for( ll i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main()
{
    ll w, a, diff; cin >> w >> a >> diff;
    ll output = 1;
    for (int i=0; i<diff; i++){
        output *= (a-i)%INF;
        output = output % INF;
    }
    debug(output)
    for (int i=diff; i<w; i++){
        output *= (diff)%INF;
        output = output % INF;
    }
    debug(output)
    output *= comb(w, diff-1);
    debug(output)
    output = output % INF;
    cout << output << endl;

    return 0;
}