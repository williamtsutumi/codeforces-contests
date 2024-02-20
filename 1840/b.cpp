#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const double INF = 1e9 + 7;

int coins, dessert;

int solve(){
    if (dessert >= 32 || coins < pow(2, dessert)) return coins + 1;
    return pow(2, dessert);
}

int main()
{
    int runs; cin >> runs;
    while(runs--){
        cin >> coins >> dessert;
        cout << solve() << endl;
    }

    return 0;
}