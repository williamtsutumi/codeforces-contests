#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PER(i, a, b) for (int i = a; i >= b; i--)
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
    vi teste = {9, 8, 10, 50, 100, 1, 0, 34, 19, 98, 56, 71, 83, 92};
    // sort(teste.begin(), teste.end(), greater<int>());
    sort(teste.begin(), teste.end(), [](int a, int b)
    {
        return a < b;
    });

    for (int t : teste)
        cout << t << " ";
    cout << endl;

    return 0;
}