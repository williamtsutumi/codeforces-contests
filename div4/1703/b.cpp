#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
#endif

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
        int n; cin >> n;
        string in; cin >> in;

        map<int,int> mp;
        for (int i=0; i<n; i++){
            if (mp[in[i]] == 0) mp[in[i]] += 2;
            else mp[in[i]]++;
        }
        ll out = 0;
        for (auto &[k,v]:mp){
            out += v;
        }
        cout << out << '\n';
    }

    return 0;
}
