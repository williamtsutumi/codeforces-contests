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

ll solve(vector<int> &in){
    vector<int> zeros(in.size()+1);
    zeros[0] = 0;
    for (int i=1; i<=in.size(); i++){
        zeros[i] = zeros[i-1] + (int)(in[i-1] == 0);
    }
    ll out = 0;
    for (int i=0; i<in.size(); i++){
        if (in[i] == 1){
            out += zeros[in.size()] - zeros[i];
        }
    }
    return out;
}


int main()
{
    FFIO;

    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        vector<int> in(n);
        for(int i=0; i<n; i++) cin >> in[i];


        ll out = solve(in);
        int fzero = -1;
        for (int i=0; i<n; i++){
            if (in[i] == 0){
                fzero = i;
                break;
            }
        }
        if (fzero != -1){
            in[fzero] = 1;
            out = max(out, solve(in));
            in[fzero] = 0;
        }

        int lone = -1;
        for (int i=0; i<n; i++){
            if (in[i] == 1){
                lone = i;
            }
        }
        if (lone != -1){
            in[lone] = 0;
            out = max(out, solve(in));
        }
        cout << out << '\n';
    }

    return 0;
}
