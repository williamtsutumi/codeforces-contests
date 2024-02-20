#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
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

bool solve(vector<pair<int,int>> &v, int k){
    int t = 0;
    int b = 0;
    pair<int,int> poss = {0, 1e9};
    for (int i=0; i<v.size(); i++){
        pair<int,int> p = v[i];
        if (t + k < p.first) return false;
        if (b - k > p.second) return false;
        if (b > t) return false;
        t = min(p.second, t + k);
        b = max(p.first, b - k);
    }
    return b <= t;
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        vector<pair<int,int>> v(n);
        for (int i=0; i<n; i++){
            int a,b; cin >> a >> b;
            v[i] = {a,b};
        }

        int hi = 1e9;
        int lo = 0;
        while (lo <= hi){
            int mid = (hi+lo)/2;
            if (solve(v, mid)){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        cout << lo << '\n';
    }

    return 0;
}
