#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long double ld;
typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int main()
{
    FFIO;
    int runs; cin >> runs;
    while(runs--){
      int n, k; cin >> n >> k;
      vector<string> in(n);
      for (int i=0; i<n; i++) cin >> in[i];

      for (int i=0; i<n; i+=k){
        for (int j=0; j<n; j+=k){
          cout << in[i][j];
        }
        cout << '\n';
      }
    }

    return 0;
}
