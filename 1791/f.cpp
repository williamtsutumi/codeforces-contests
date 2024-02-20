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
    int runs; cin >> runs;
    while (runs--)
    {
        int len, queries; cin >> len >> queries;

        vi inputs(len);
        for (int i = 0; i < len; i++)
        {
            int in; cin >> in;
            inputs[i] = in;
        }

        for (int i = 0; i < queries; i++)
        {
            int op, from, to; cin >> op >> from >> to;

            
        }
    }

    return 0;
}