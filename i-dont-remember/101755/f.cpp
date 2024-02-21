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
    int n; cin >> n;
    vector<vector<int>> vet(n);
    map<int,int> mp;
    for(int i=0; i<n; i++){
        int child; cin >> child;
        // child--;
        vet[i].resize(child);
        for(int j=0; j<child; j++){
            int in; cin >> in;

            
            in--;
            vet[i][j] = in;
            mp[in]++;
        }
    }
    // debug(vet);
    vector<int> depth(n);
    for(auto &[key, val] : mp){
        // if (val == n){
        //     cout << "NO" << endl;
        //     return 0;
        // }
        depth[val] = key;
    }
    debug(depth);
    for(int i=0; i<n-1; i++){
        if (find(depth.begin(), depth.end(), i) == depth.end() && find(depth.begin(), depth.end(), i+1) != depth.end()){
            cout << "NO" << endl;
            return 0;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (depth[i] == depth[j]+1){
                // debug(i, j);
                if (find(vet[j].begin(), vet[j].end(), i) != vet[j].end()){
                    cout << i+1 << " " << j+1 << endl;
                }
            }
        }
    }
    // cout << "A" << endl;
    return 0;
}