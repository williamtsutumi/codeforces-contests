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

int main()
{
    int runs; cin >> runs;
    while (runs--){
        string in; cin >> in;
        vector<int> dist(10);
        int curr = 1;
        int out = 0;
        for (int i=0; i<in.size(); i++){
            // debug(out);
            if (curr != 0){
                if (in[i] != '0') out += abs(in[i] - '0' - curr);
                else out += 10 - curr;
            }
            else{
                if (in[i] != '0') out += 10 - (in[i] - '0') - curr;
            }
            out++;
    
            curr = in[i] - '0';
        }
        cout << out << '\n';
    }

    return 0;
}
