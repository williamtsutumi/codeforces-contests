#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int get_val(vector<vector<int>> &v, int l, int r){
    int out = 0;
    for (int i=0; i<32; i++){
        //debug(i, l, r, v[i][r], v[i][l]);
        if (v[i][r] - v[i][l-1] == r - l + 1) out |= 1 << i;
    } 
    return out;
}

int main()
{
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        vector<int> in(n);
        for (int i=0; i<n; i++) cin >> in[i];
        
        vector<vector<int>> v(33);
        for (int i=0; i<32; i++) v[i].resize(n+2, 0);

        for (int i=0; i<n; i++){
            for (int j=0; j<32; j++){
                if (i == 0 && in[i] & (1 << j)){
                    v[j][i] = 1;
                }
                else{
                    if (in[i] & (1 << j)){
                        v[j][i] = v[j][i-1] + 1;
                    }
                    else{
                        v[j][i] = v[j][i-1];
                    }
                }
            }
        }
        int q; cin >> q;
        for (int j=0; j<q; j++){
            int l, k; cin >> l >> k;
            int low = l-1;
            int high = n-1;
            while (low <= high){
                int mid = (low + high) / 2;
                int val = get_val(v, l-1, mid);
                if (val >= k) low = mid + 1;
                else high = mid - 1;
            }
            int s = low; 
            if (s < l) s = -1; 
            cout << s << ' ';
        }
        cout << '\n';
    }

    return 0;
}
