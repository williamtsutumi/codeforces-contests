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

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        int out = -1;
        int mx = -1;
        for (int i=1; i<=n; i++){
            int a, b; cin >> a >> b;
            if (a <= 10){
                if (mx == -1 || mx < b){
                    out = i;
                    mx = b;
                }
            }
        }
        cout << out << '\n';
    }

    return 0;
}
