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
        vector<int> v(n);
        for(int i=0; i<n; i++) cin >> v[i];

        int odds = 0;
        for (int i=0; i<n; i++){
            if (v[i] % 2 == 1) odds++;
        }
        if (odds % 2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
