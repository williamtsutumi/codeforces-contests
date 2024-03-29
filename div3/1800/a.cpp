#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
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
        for(int i=0; i<n; i++) in[i] = tolower(in[i]);
        in.resize(distance(in.begin(), unique(in.begin(), in.end())));
        
        bool ok = in == "meow";

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
