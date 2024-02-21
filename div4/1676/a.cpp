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
        string in; cin >> in;

        if ((int)in[0] + (int)in[1] +(int)in[2] == (int)in[3]+(int)in[4]+(int)in[5]){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }

    return 0;
}
