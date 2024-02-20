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
        vector<int> in(n);
        for(int i=0; i<n; i++) cin >> in[i];

        multiset<int> st;
        ll out = 0;
        for(int i=0; i<n; i++){
            int dst = distance(lower_bound(st.begin(), st.end(), in[i]), st.end());
            out += dst;

            st.insert(in[i]);
        }
        cout << out << '\n';
    }

    return 0;
}
