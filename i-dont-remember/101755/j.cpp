#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double
#define X real()
#define Y imag()

typedef long long C;
typedef complex<C> P;
typedef long long ll;
const double INF = 1e9 + 7;

int main()
{
    int n; cin >> n;
    map<int,int> mp;
    for(int i=0; i<n; i++){
        int in; cin >> in;
        mp[in]++;
    }
    int pairs = 0;
    for (auto &[key, val] : mp){
        pairs += val / 2;
    }
    cout << pairs / 2 << endl;
    return 0;
}