#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const double INF = 1e9 + 7;

int main()
{
    int n;cin>>n;
    vector<pair<int,bool>> vet(n);
    ll sum = 0;
    for(int i=0; i<n; i++){
        int in; cin >> in;
        vet[i] = make_pair(in, true);
        sum += vet[i].first;
    }
    if (sum >= n){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int idx = n-1;
    for(int i=n-1; i>=0; i--){
        int val = vet[i].first;
        for(int j=0; j<val; j++){
            if(vet[idx].second){
                vet[idx].second = false;
                cout << i+1 << " " << idx+1 << endl;
                idx--;
            }
            else{
                j--;
            }
        }
    }

    return 0;
}