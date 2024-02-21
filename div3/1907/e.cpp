#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

ll dsum(int a){
    ll out = 0;
    for (int i=0; i<8; i++){
        out += a % 10;
        a /= 10;
    }
    return out;
}

ll digsum(int a, int b, int c){
    ll out = 0;
    for (int i=0; i<8; i++){
        out += (a % 10) + (b % 10) + (c % 10);
        a /= 10; b /= 10; c /= 10;
    }
    return out;
}

ll solve(int curr, int target, int targetDsum){
    ll out = 0;
    int its = target - curr;
    for (int i=0; i<=its; i++){

        if(digsum(curr, i, target - i) == targetDsum) out++;
    }
    return out;
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;

        ll disum = dsum(n);
        ll out = 0;
        debug(n);
        for (int i=0; i<=n; i++){
            if (dsum(i) > disum) continue;

            out += solve(i, n, disum);
        }
        cout << out << '\n';
    }

    return 0;
}
