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
        int n1, n2; cin >> n1 >> n2;

        vector<int> a(n1);
        vector<int> b(n2);
        for (int i=0; i<n1; i++) cin >> a[i];
        for (int i=0; i<n2; i++) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater());
        int its = min(n1, n2);
        ll sum = 0;
        int hi = n2-1;
        int lo = 0;
        int hi2 = n1-1;
        int lo2 = 0;
        for (int i=0; i<its; i++){
            int vallo = abs(a[hi2]-b[lo]);
            int valhi = abs(a[lo2]-b[hi]);
            int vallo2 = abs(a[lo2]-b[lo]);
            int valhi2= abs(a[hi2]-b[hi]);
            int mx = max({vallo, valhi, vallo2, valhi2});
            if (mx == vallo){
                hi2--;
                lo++;
            }
            else if (mx == vallo2){
                lo2++;
                lo++;
            }
            else if (mx == valhi){
                lo2++;
                hi--;
            }
            else if (mx == valhi2){
                hi2--;
                hi--;
            }
            sum += mx;
        }
        cout << sum << '\n';

    }

    return 0;
}
