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
        vector<string> v(10);
        for (int i=0; i<10; i++) cin >> v[i];

        int out = 0;
        for (int i=0; i<10; i++){
            for (int j=0; j<10; j++){
                int x = i, y = j;
                if (i >= 5) x = abs(i-9);
                if (j >= 5) y = abs(j-9);
                int a = min(6-abs(5-x), 6-abs(5-y));
                if (v[i][j] == 'X'){
                    out += a;
                }
            }
        }
        cout << out << '\n';
    }

    return 0;
}
