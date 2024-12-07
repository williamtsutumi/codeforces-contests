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
        int val; cin >> val;

        int curr = 0;
        for(int i=0; i<in.size(); i++){ curr += in[i] -'a' + 1; }

        vector<stack<int>> v(30);
        for(int i=0; i<in.size(); i++){
            v[in[i]-'a'].push(i);
        }

        bool has[200000];
        memset(has, true, sizeof has);
        while(curr > val){
            for(char c='z'; c>='a'; c--){
                int idx = c-'a';
                if (!v[idx].empty()){
                    curr -= idx+1;
                    has[v[idx].top()] = false;
                    v[idx].pop();
                    break;
                }
            }
        }
        for(int i=0; i<in.size(); i++){
            if (has[i]) cout << in[i];
        }
        cout << '\n'; 
    }

    return 0;
}
