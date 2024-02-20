#ifdef ONLINE_JUDGE
  #define debug(x...)
#else
  #include "/mnt/c/Projetos/beecrowd/debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const double INF = 1e9 + 7;

int main()
{
    int runs; cin >> runs;
    while(runs--){
        int p, steps, k, h; cin >> p >> steps >> k >> h;
        int maximo = (steps-1)*k;
        int ans = 0;
        for(int i=0; i<p; i++){
            int in; cin >> in;
    	    if (in != h && abs(in - h) % k == 0 && abs(in-h) <= maximo){
                ans++;
            }
        }
        cout << ans << endl;
    }


    return 0;
}