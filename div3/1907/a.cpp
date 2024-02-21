#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
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
        string in; cin >> in;
        for(char a='a'; a<='h'; a++){
            if (in[0] != a) cout << a << in[1] << '\n';
        }
        for (char a='1'; a<='8'; a++){
            if (in[1] != a) cout << in[0] << a << '\n';
        }
    }

    return 0;
}
