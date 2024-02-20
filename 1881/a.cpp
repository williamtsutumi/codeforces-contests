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
    int r; cin >> r;
    while(r--){
        int a, b; cin >> a >> b;
        string s1, s2; cin >> s1 >> s2;
        
        int j = 0;
        bool ok = false;
        while(j < 2 || s1.length() < s2.length() * 3) {
            if (s1.find(s2) != string::npos){
                cout << j << endl;
                ok = true;
                break;
            }
            j++;
            s1 += s1;
        }
        if (!ok) cout << -1 << endl;
    }

    return 0;
}
