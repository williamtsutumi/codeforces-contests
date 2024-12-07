#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int lis(vector<int>& arr)
{
    vector<int> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
        if (it == ans.end()) {
            ans.push_back(arr[i]);
        }
        else {
            *it = arr[i];
        }
    }
    return ans.size();
}


int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        vector<int> in(n);
        for(int i=0; i<n; i++) cin >> in[i];
        if (n <= 2){
            cout << 0 << '\n';
            continue;
        }


        int l = INT_MAX;
        int r = INT_MAX;
        int out = 0;
        for(int i=0; i<n; i++){
            int v = in[i];
            if (v <= l && v <= r){
                if (l > r) r = v;
                else l = v;
            }
            else if (v <= l){
                l = v;
            }
            else if (v <= r){
                r = v;
            }
            else{
                out++;
                if (l > r) r = v;
                else l = v;
            }
        }
        cout << out << '\n';
    }

    return 0;
}
/*
 * 8 2 3 1 1 7 4 3
 * 8 3
 * 2 1 1 7 4 3
 *
 * 8 2 3 4 1 7 4 3
 * 8 3 1 7
 * 2 4 4 3
 */
