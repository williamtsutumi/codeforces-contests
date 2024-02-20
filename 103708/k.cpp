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

vector<int> vet;
int dp[500000];

int solve(int in){
    memset(dp, -1, 100 * sizeof(int));


}

int main()
{
    int dinners, pres; cin >> dinners >> pres;
    vet.resize(pres);
    for(int i=0; i<pres; i++){
        cin >> vet[i];
    }
    for(int i=0; i<dinners; i++){
        int in; cin >> in;
        cout << solve(in) << endl;
    }


    return 0;
}