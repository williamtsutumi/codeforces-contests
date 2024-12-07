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

bool check(string &str, int sz){
    string sub = str.substr(0, sz);
    int diff = 0;
    for(int i=0; i<str.size(); i++){
        if (str[i] != sub[i%sz]) diff++;
        if (diff == 2) return false;
    }
    return true;
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        string in; cin >> in;

        bool ok = false;
        int its = in.size() / 2;
        for(int i=1; i<its; i++){
            if (i % n != 0) continue;

            for(char c='a'; c<='z'; c++){
                string aux = in;
                if (check(aux, i)){
                    cout << i << '\n';
                    ok = true;
                }
            }
        }
        if (ok) continue;
        cout << n << '\n';
    }

    return 0;
}
