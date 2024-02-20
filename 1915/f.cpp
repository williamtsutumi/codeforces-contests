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

        vector<pair<int,int>> in(n);
        for (int i=0; i<n; i++){
            int a,b; cin >> a >> b;
            in[i] = {a,b};
        }

        sort(in.begin(), in.end(), [](pair<int,int> a, pair<int,int> b) -> bool { return a.second < b.second; });

        ll out = 0;



        cout << out << '\n';
    }

    return 0;
}
