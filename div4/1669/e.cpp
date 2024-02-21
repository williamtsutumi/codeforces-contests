#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
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
        vector<string> in(n);
        for(int i=0; i<n; i++) cin >> in[i];

        map<pair<char,char>,int> mp;
        for(char a='a'; a<='k'; a++){
            for(char j='a'; j<='k'; j++){
                for(int i=0; i<n; i++){
                    if (in[i][0] == a && in[i][1] != j){
                        mp[make_pair(a,j)]++;
                    }
                    else if (in[i][0] != a && in[i][1] == j){
                        mp[make_pair(a,j)]++;
                    }
                }
            }
        }
        ll out = 0;
        for(int i=0; i<n; i++){
            out += mp[make_pair(in[i][0], in[i][1])];
        }
        cout << out/2 << '\n';
    }

    return 0;
}
