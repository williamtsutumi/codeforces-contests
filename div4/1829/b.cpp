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
        for(int i=0;i<n;i++) cin >> in[i];

        int cnt = 0;
        int mx = INT_MIN;
        for (int i=0; i<n; i++){
            if (in[i] == 0){
                cnt++;
            }
            else{
                mx = max(mx, cnt);
                cnt= 0;
            }
            if (i == n-1){
                mx = max(mx, cnt);
                cnt= 0;
            }
        }
        cout << mx << '\n';
    }

    return 0;
}
