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

        string origin; cin >> origin;
        string target; cin >> target;

        int cnt1,cnt2;
        cnt1 = cnt2 = 0;
        ll sum1 = 0;
        ll sum2 = 0;
        for (int i=0; i<n; i++){
            if (origin[i] == '1') cnt1++;
            if (target[i] == '1') cnt2++;
            if (origin[i] == '1' && target[i] == '0') sum1++;
            if (origin[i] == '0' && target[i] == '1') sum2++;
        }
        int cei = abs(cnt1-cnt2) + (min(sum1, sum2));
        cout << cei<< '\n';
    }

    return 0;
}
