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

ll calc(vector<int> &v, int val){
    ll out = 0;
    for (int i=0; i<v.size(); i++){
        if (val > v[i]){
            out += val - v[i];
        }
    }
    return out;
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        ll n, water; cin >> n >> water;
        vector<int> v(n);
        for(int i=0; i<n; i++) cin >> v[i];

        ll low = 0;
        ll high = INT_MAX;
        ll mid;
        while(low <= high){
            mid = (low + high) / 2;
            ll c = calc(v,mid);
            if (c <= water) low = mid + 1;
            else high = mid - 1;
        }
        cout << low-1 << '\n';
    }
    return 0;
}
