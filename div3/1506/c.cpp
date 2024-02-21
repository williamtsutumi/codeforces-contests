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
        string a, b; cin >> a >> b;
        if (b.size() > a.size()) swap(a, b);

        int sz = -1;
        for(int i=0; i<b.size(); i++){
            for(int j=0; j<=b.size(); j++){
                if (i + j > b.size()) break;
                if (a.find(b.substr(i, j)) != string::npos){
                    sz = max(sz, j);
                }
            }
        }
        cout << a.size() - sz + b.size() - sz << '\n';
    }

    return 0;
}
