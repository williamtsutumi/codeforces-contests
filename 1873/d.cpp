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
        string in; cin >> in;
        ll out = 0;
        for (int i=0; i<in.length(); i++){
            if (in[i] == 'B'){
                out++;
                i += k-1;
            }
        }
        cout << out << '\n';
    }

    return 0;
}
