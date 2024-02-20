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


ll solve(vector<int> &a, vector<int> &b){
    int n = a.size();

    bool ok = true;
    int turn = 0;
    while (ok){
        int mx = INT_MIN;
        int idx = -1;
        for (int i=0; i<n; i++){
            if (a[i] > 0 && b[i] > 0){
                if (a[i] + b[i] > mx){
                    mx = a[i] + b[i];
                    idx = i;
                }
            }
        }
        if (turn == 0){
            a[idx]--;
            b[idx] = 0;
        }
        else{
            b[idx]--;
            a[idx] = 0;
        }
        turn = (turn+1)%2;
        ok = false;
        for (int i=0; i<n; i++){
            if (a[i] > 0 && b[i] > 0){
                ok = true;
            }
        }
    }

    ll out = 0;
    for (int i=0; i<n; i++) out += a[i];
    for (int i=0; i<n; i++) out -= b[i];
    return out;
}

int main()
{
    FFIO;
    int r; cin >> r;
    vector<int> a;
    vector<int> b;
    while(r--){
        int n; cin >> n;
        a.resize(n);
        b.resize(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];

        ll s = solve(a,b);
        cout << s << '\n';
    }

    return 0;
}
