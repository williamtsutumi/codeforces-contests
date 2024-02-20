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
        int n, d; cin >> n >> d;
        string in; cin >> in;

        int idx = -1;
        for(int i=0; i<n; i++){
            if (in[i] -'0' < d){
                idx = i;
                break;
            }
        }
        for(int i=0; i<in.size(); i++){
            if (d == in[i]-'0' && i == 0) cout << d;
            else if (d < in[i]-'0' && i == n-1) cout << d;
            else if (i == idx) cout << d;
            cout << in[i];
        }
        if (d == 0) cout << d;
        cout << '\n';
    }

    return 0;
}
