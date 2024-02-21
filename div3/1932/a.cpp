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
        string in; cin >> in;

        ll coins = 0;
        for(int i=0; i<n; i++){
            if (in[i] == '*') break;
            if (in[i] == '@') coins++;
            if (i+1 < n && in[i+1] == '*') i++;
        }
        cout << coins << '\n';
    }

    return 0;
}
