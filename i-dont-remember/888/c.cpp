#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
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
        // cout << "*****\n";
        int n, k; cin >> n >> k;
        vector<int> vet(n);
        for(int i=0; i<n; i++) cin >> vet[i];
        if (k==1){
            cout << "YES" << endl;
            continue;
        }

        int first = vet[0];
        int last = vet[n-1];

        int idx1 = -1, count = 0;
        while(idx1 < n && count < k){
            idx1++;
            if (vet[idx1] == first){
                count++;
            }
        }
        if (first == last && idx1 < n){
            cout << "YES" << endl;
            continue;
        }
        if (idx1 == n){
            cout << "NO" << endl;
            continue;
        }

        int idx2 = n, count2 = 0;
        while(idx2 >= 0 && count2 < k){
            idx2--;
            if(vet[idx2] == last){
                // debug(vet[idx2], idx2);
                
                count2++;
            }
        }
        // debug(idx1, idx2);
        if (idx2 < 0 || idx2 < idx1){
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }

    return 0;
}