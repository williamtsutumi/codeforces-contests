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

vector<int> in;
int k;

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n >> k;
        in.resize(n);
        for(int i=0; i<n; i++) cin >> in[i];

        map<int,int> mp;
        for(int i=0; i<n; i++) mp[in[i]]++;

        sort(in.begin(), in.end());
        vector<int> good;
        for(auto &[useless,v]:mp){
            if (v >= k) good.push_back(useless);
        }
        if (good.size() == 0){
            cout << -1 << '\n';
            continue;
        }

        int start = good[0];
        int cnt = 0;
        pair<int,int> out;
        for(int i=1; i<=good.size(); i++){
            if (i != good.size() && good[i-1] == good[i] - 1) cnt++;
            else{
                if (cnt >= out.second - out.first){
                    out = {start, start + cnt};
                }
                if (i < good.size()) start = good[i];
                cnt = 0;
            }
        }

        if (out == make_pair(0,0)) cout << -1 << '\n';
        else cout << out.first << ' ' << out.second << '\n';
    }

    return 0;
}
