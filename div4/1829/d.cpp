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

bool solve(int sz, int target){
    if (sz == target) return true;
    if (sz % 3 != 0) return false;

    return solve(sz / 3, target) || solve(2*(sz/3), target);
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int sz, target; cin >> sz >> target;

        if (solve(sz,target)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
