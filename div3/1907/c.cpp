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
        int n; cin >> n;
        string in; cin >> in;
        if (n == 1){
            cout << 1 << '\n';
            continue;
        }

        vector<ll> v(30, 0);
        for (int i=0; i<n; i++){
            int idx = in[i]-'a';
            v[idx]++;
        }
        sort(v.begin(), v.end(), [](int a, int b) -> bool{ return a > b; });
        ll sum = 0;
        for (int i=1; i<30; i++){
            sum += v[i];
        }
        if (v[0] > sum){
            cout << v[0] - sum << '\n';
        }
        else{
            cout << (int)(n % 2 != 0) << '\n';
        }
    }

    return 0;
}
