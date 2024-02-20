#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (ll i = a; i <= b; i++)
#define PER(i, a, b) for (ll i = a; i >= b; i--)
#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
const double INF = 1e9 + 7;

int main()
{
    ll runs; cin >> runs;
    while (runs--)
    {
        ll inputs; cin >> inputs;
        ll negativos = 0;
        vi vet(inputs);
        for (ll i = 0; i < inputs; i++)
        {
            ll in; cin >> in;
            vet[i] = in;

            if (in <= 0)
                negativos++;
        }
        sort(vet.begin(), vet.end(), [](ll a, ll b) {
            return abs(a) < abs(b);
        });

        ll output = 0;
        if (negativos % 2 == 1)
            output -= abs(vet[0]);
        else
            output += abs(vet[0]);

        for (ll i = 1; i < inputs; i++)
            output += abs(vet[i]);
        cout << output << endl;
    }

    return 0;
}