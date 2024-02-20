#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const double INF = 1e9 + 7;

int main()
{
    int runs; cin >> runs;
    while(runs--){
        ll x1, x2, x3, y1, y2, y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        complex<ll> p1, p2, p3;
        p1 = {x1,y1}; p2 = {x2,y2}; p3 = {x3,y3};
        complex<ll> aux1 = p3 - p1;
        complex<ll> aux2 = p3 - p2;
        ll r = aux1.real() * aux2.imag() - aux2.real() * aux1.imag();
        if (r > 0) cout << "LEFT" << endl;
        else if (r < 0) cout << "RIGHT" << endl;
        else cout << "TOUCH" << endl;
    }

    return 0;
}