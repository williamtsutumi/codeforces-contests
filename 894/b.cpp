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
        int n; cin >> n;
        vector<int> vet(n);
        vector<int> out;
        cin >> vet[0];
        out.push_back(vet[0]);
        int idx = 0;
        for(int i=1; i<n; i++){
            cin >> vet[i];
            // debug(vet);
            if (vet[i-1] <= vet[i]){
                out.push_back(vet[i]);
                idx++;
            }
            else{
                out.push_back(vet[i]);
                idx++;
                out.push_back(vet[i]);
                idx++;
            }
        }
        // debug(idx);
        cout << idx+1 << '\n';
        for(int i=0; i<idx+1; i++){
            cout << out[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}