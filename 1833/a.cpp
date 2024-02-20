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
    while (r--){
        int n; cin >> n;
        string str; cin >> str;

        map<string,int> mp;
        for (int i=0; i<str.size()-1; i++){
            string s = str.substr(i, 2);
            mp[s]++;
        }
        int cnt = 0;
        for (auto [k,v]: mp){
            if (v > 0) cnt++;
        }
        cout << cnt << '\n';
    }

    return 0;
}
