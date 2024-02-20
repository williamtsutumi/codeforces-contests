#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
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

vector<string> read(){
    string line;
    vector<string> out;
    while(getline(cin, line)){
        stringstream ss(line);
        string str;
        while(getline(ss, str, ' ')){
            out.push_back(str);
        }
    }
    return out;
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n, k; cin >> n >> k;

        vector<int> val(n);
        vector<int> h(n);
        for (int i=0; i<n; i++) cin >> val[i];
        for (int i=0; i<n; i++) cin >> h[i];

        int l = 0;
        int r = 1;
        ll sum = 0;
        if (n > 1) sum = val[l] + val[r];
        int out = 0;
        while(r < n){
            if (h[r-1] % h[r] != 0){
                out = max(out, r - l + 1);
                l = r;
                r++;
                sum = val[l] + val[r];
            }
            else if (sum >= k){
                sum -= val[l];
                l++;
                if (l == r) r++;
            }
            else{
                r++;
                sum += val[r];
            }
        }
        cout << out << '\n';
    }

    return 0;
}
