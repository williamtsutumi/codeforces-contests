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

int solve(string str1, string str2){
    int out = 0;
    for(int i=0; i<str2.size(); i++){
        out += abs((int)str1[i] - (int)str2[i]);
    }
    return out;
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n, sz; cin >> n >> sz;

        vector<string> in(n);
        for(int i=0; i<n; i++) cin >> in[i];

        int out = INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                out = min(out, solve(in[i], in[j]));
            }
        }
        cout << out << '\n';
    }

    return 0;
}
