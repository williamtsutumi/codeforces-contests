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
        ll n, charge, pertime, turnon; cin >> n >> charge >> pertime >> turnon;

        vector<ll> messages(n+1);
        messages[0] = 0;
        for(int i=1; i<=n; i++) cin >> messages[i];

        sort(messages.begin(), messages.end());

        bool ok = true;
        for (int i=0; i<n; i++){
            ll mn = pertime * (messages[i+1] - messages[i]);
            mn = min(mn, turnon);
            charge -= mn;
            if (charge <= 0){
                ok = false;
                break;
            }

        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
