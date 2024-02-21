#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
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
        int n; cin >> n;
        int out;
        if (1900 <= n) out = 1;
        else if (1600 <= n && n <= 1899) out = 2;
        else if (1400 <= n && n <= 1599) out = 3;
        else out = 4;
        cout << "Division " << out << '\n';
    }

    return 0;
}
