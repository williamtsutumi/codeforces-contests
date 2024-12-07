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
        vector<int> in(3);
        cin >> in[0] >> in[1] >> in[2];
        if (in[0] < in[1] && in[1] < in[2]) cout << "STAIR\n";
        else if (in[0] < in[1] && in[1] > in[2]) cout << "PEAK\n";
        else cout << "NONE\n";
    }

    return 0;
}
