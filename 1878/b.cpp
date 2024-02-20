#ifdef ONLINE_JUDGE
#define debug(x...)
#else
#include "/mnt/c/Projetos/beecrowd/debug.h"
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
    FFIO;
    int r; cin >> r;
    int p1 = 0;
    int p2 = 0;
    while(r--){
        int n; cin >> n;
        vector<int> v = {1, 3};
        for (int i=2; i<n; i++){
            for (int j=v[i-1] + 1; true; j++){
                if ((3 * j) % (v[i-1] + v[i-2]) != 0){
                    v.push_back(j);
                    break;
                }
            }
        }
        for (int i=0; i<n; i++){
            cout << v[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
