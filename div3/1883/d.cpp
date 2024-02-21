#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
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
    int n; cin >> n;
    multiset<int> left;
    multiset<int> right;
    for (int i=0; i<n; i++){
        char c; cin >> c;
        int l, r; cin >> l >> r;

        if (c == '+'){
            left.insert(l);
            right.insert(r);
        }
        else if (c == '-'){
            left.erase(left.find(l));
            right.erase(right.find(r));
        }
        if (left.empty()){
            cout << "NO\n";
            continue;
        }
        int rightmost = *(left.rbegin());
        int leftmost = *(right.begin());    

        if (leftmost < rightmost) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
