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
        int n; cin >> n;
        vector<ll> v(n);
        for (int i=0; i<n; i++) cin >> v[i];

        ll mn = INT_MAX;
        ll idx = -1;
        for (int i=0; i<n; i++){
            if (v[i] < mn){
                mn = v[i];
                idx = i;
            }
        }
        v[idx]++;
        ll out = 1;
        for (int i=0; i<n; i++){
            out *= v[i];
        }
        cout << out << '\n';
    }

    return 0;
}
