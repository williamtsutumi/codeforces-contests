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
        string in; cin >> in;

        set<char> st;
        ll out = 1;
        for(int i=0; i<in.size(); i++){
            st.insert(in[i]);

            if (st.size() > 3){
                st.clear();
                st.insert(in[i]);
                out++;
            }
        }
        cout << out << '\n';
    }

    return 0;
}
