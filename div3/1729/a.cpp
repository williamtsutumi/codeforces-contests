
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
        int a, b, c; cin >> a >> b >> c;
        int timea = a - 1;
        int timeb = (c > b) ? ((c - b) + (c - 1)) : (b - 1);
        if (timea == timeb) cout << 3 << '\n';
        else if (timea < timeb) cout << 1 << '\n';
        else cout << 2 << '\n';
    }

    return 0;
}
