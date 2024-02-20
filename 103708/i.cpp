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
    string n; cin >> n;
    ll output = 0;
    for(char c : n){
        if (c-'0' == 0) continue;
        if (((stoi(n)) % (c-'0')) == 0) output++;
    }
    cout << output << endl;


    return 0;
}