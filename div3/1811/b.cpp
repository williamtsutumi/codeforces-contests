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

int n;

int layer(pair<int,int> p){
    int l = p.first;
    int c = p.second;
    int out;
    int out2;
    if (l <= n/2) out = l;
    else out = n - l + 1;

    if (c <= n/2) out2 = c;
    else out2 = n - c + 1;

    return min(out, out2);
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        cin >> n;
        pair<int,int> from, to;
        cin >> from.second >> from.first >> to.second >> to.first;

        int l1 = layer(from);
        int l2 = layer(to);
        cout << abs(layer(from) - layer(to)) << '\n';
    }

    return 0;
}
