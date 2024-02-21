#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
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
        int its = ((n-1)*n)/2;
        vector<int> v(its);
        for(int i=0; i<its; i++) cin >> v[i];

        sort(v.begin(), v.end(), [](int a, int b) -> bool { return b < a; });
        int count = 1;
        int expected = 1;
        if (n == 2){
            cout << v[0] << ' ' << v[0] << '\n';
            continue;
        }
        cout << v[0] << ' ';
        for (int i=1; i<=its; i++){
            if (i == its || v[i] != v[i-1]) {
                int a = expected;
                int it = 1;
                while (count > a){
                    it++;
                    expected++;
                    a += expected;
                }
                for (int j=0; j<it; j++) cout << v[i-1] << ' ';

                expected++;
                count = 0;
            }
            else{
                count++;
            }
        }
        cout << '\n';
    }

    return 0;
}
