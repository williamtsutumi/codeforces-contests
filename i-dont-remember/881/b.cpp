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
        int n; cin >> n;
        vector<int> vet;
        for(int i=0; i<n; i++){
            int in; cin >> in;
            if (in != 0) vet.push_back(in);
        }

        ll output = 0;
        for(int i=0; i<vet.size(); i++){
            if (vet[i] < 0 && (vet[i+1] > 0 || i+1 == vet.size())){
                output++;
            }
        }
        ll sum = 0;
        for(int i=0; i<vet.size(); i++){
            sum += abs(vet[i]);
        }
        cout << sum << " " << output << endl;
    }

    return 0;
}