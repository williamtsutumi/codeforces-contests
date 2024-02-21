#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
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

ll solve(vector<int> &a, vector<int> &b, vector<int> &c){
    int n = a.size();
    int mxa = INT_MIN;
    int idxa = -1;
    for (int i=0; i<n; i++){
        if (a[i] > mxa){
            mxa = a[i];
            idxa = i;
        }
    }
    int mxb = INT_MIN;
    int idxb = -1;
    for (int i=0; i<n; i++){
        if (i != idxa && b[i] > mxb){
            mxb = b[i];
            idxb = i;
        }
    }
    int mxc = INT_MIN;
    for (int i=0; i<n; i++){
        if (i != idxa && i != idxb && c[i] > mxc){
            mxc = c[i];
        }
    }
    return mxa + mxb + mxc;
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;

        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];
        for (int i=0; i<n; i++) cin >> c[i];

        ll out = solve(a,b,c);
        swap(b,c);
        out = max(out, solve(a,b,c));
        swap(b,c);
        swap(a,b);
        out = max(out, solve(a,b,c));
        swap(a,c);
        out = max(out, solve(a,b,c));
        swap(a,b);
        swap(a,c);
        out = max(out, solve(a,b,c));
        swap(a,b);
        out = max(out, solve(a,b,c));
        cout << out << '\n';
        /*
         * a b c
         * a c b
         * a b c
         * b a c
         * b c a
         * a c b
         * c a b
         * c b a
         * */
    }

    return 0;
}
