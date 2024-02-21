#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double
#define X real()
#define Y imag()

typedef complex<ll> P;
typedef long long ll;
const double INF = 1e9 + 7;

int main()
{
    int n, min; cin >> n >> min;
    vector<int> vet(n+1);
    for(int i=0; i<n; i++){
        int in; cin >> in;
        vet[in]++;
    }
    

    return 0;
}