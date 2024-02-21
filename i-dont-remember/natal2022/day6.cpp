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
    string in; cin >> in;
    map<int,int> mp;
    for (int i=0; i<14; i++){
        mp[in[i]]++;
    }
    for (int i=14; i<in.size(); i++){
        bool found = true;
        for(auto [k,v] : mp){
            debug(v);
            if (v > 1) found = false;
        }
        if(found){
            cout << i << endl;
            break;
        } 
        mp[in[i]]++;

        char to_remove = in[i-14];
        mp[to_remove]--;
        if (mp.at(to_remove) == 0) mp.erase(to_remove);
    }

    
    return 0;
}
