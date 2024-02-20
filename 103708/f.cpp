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
const ll INF = 1e9 + 7;

vector<int> vet;

int main()
{
    int steps, holes; cin >> steps >> holes;
    vet.resize(holes);
    for(int i=0; i<holes; i++){
        int h; cin >> vet[i];
    }

    sort(vet.begin(), vet.end());
    for(int i=0; i<holes-1; i++){
        if (vet[i] == vet[i+1]-1){
            cout << 0 << endl;
            return 0;
        }
    }

    ll output = 0;
    ll last = 0;
    for(int i=1; i<holes; i++){
        output *= solve(vet[i] - vet[i-1] - 2) % INF;
        output = output % INF;
    }
    cout << output << endl;

    return 0;
}