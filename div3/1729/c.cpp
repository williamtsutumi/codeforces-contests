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
        string str; cin >> str;
        int n = str.size();

        map<int,vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[str[i]].push_back(i);
        }


        char f = str[0];
        char l = str[n-1];

        int sz = 0;
        int st = min(f, l);
        int fs = max(f,l);
        for(char c=st; c<=fs; c++){
            auto v = mp[c];
            sz += v.size();
        }
        ll sum = abs((str[0]-'a'+1) - (str[n-1]-'a'+1));
        cout << sum << ' ' << sz << '\n';

        if (f < l){
            for(char c=f; c<=l; c++){
                auto v = mp[c];
                for(int i=0; i<v.size(); i++){
                    cout << v[i]+1 << ' ';
                }
            }
        }
        else{
            for(char c=f; c>=l; c--){
                auto v = mp[c];
                for(int i=0; i<v.size(); i++){
                    cout << v[i]+1 << ' ';
                }
            }
        }
        cout << '\n';


        
    }

    return 0;
}
