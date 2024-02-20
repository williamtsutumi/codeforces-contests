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

int main()
{
    int runs; cin >> runs;
    while(runs--){
        bool output = false;
        int n; cin >> n;
        int its = ceil(sqrt(n));
        for (int i=2; i<=its; i++){
            if (n < 7) break;
            ll pot = i;
            ll test = i;
            while (test < n){
                if (n == test + 1){
                    output = true;
                }
                pot *= i;
                test += pot;
            }
        }
        if (output) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}