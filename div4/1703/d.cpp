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
        for (int i=0; i<n; i++) cin >> in[i];

        set<string> st;
        for (int i=0; i<n; i++) st.insert(in[i]);

        for (int i=0; i<n; i++){
            int sz = in[i].size();

            string stri = in[i];
            bool ok = false;
            for (int j=1; j<sz; j++){
                string str1 = stri.substr(0, j);
                string str2 = stri.substr(j, sz-j);
                if (st.contains(str1) && st.contains(str2)){
                    ok = true;
                    break;
                }
            }
            if (ok) cout << 1;
            else cout << 0;
        }
        cout << '\n';

    }

    return 0;
}
