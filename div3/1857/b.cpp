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

int main()
{
    FFIO;
    int r; cin >> r;
    while (r--){
        string in; cin >> in;
        int found = -1;
        bool extra = false;
        for (int i=0; i<in.size(); i++){
            char d = in[i];
            if (d >= '5'){
                if (i == 0) extra = true;
                found = i;
                while (in[i-1] == '4'){
                    in[i-1] = '0';
                    i--;
                    if (i==0){
                        extra = true;
                        break;
                    }
                }
                if (!extra){
                    in[i-1] = in[i-1] + 1;
                }
                break;
            }
        }
        for (int i=found; i<in.size(); i++){
            in[i] = '0';
        }
        if (extra) cout << 1 << in << '\n';
        else cout << in << '\n';
    }

    return 0;
}
