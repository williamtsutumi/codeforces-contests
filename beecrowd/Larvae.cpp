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

ld larvae[2000];

ld area(ld a, ld b, ld c)
{
    ld p = (a + b + c) / 2;
    return p * (p - a) * (p - b) * (p - c);
}

ld solve(int lastIdx)
{
    ld output = INT_MAX;
    REP(i, 0, lastIdx)
    {
        REP(j, i + 1, lastIdx)
        {
            int lower = lower_bound(larvae, larvae + lastIdx + 1, larvae[j] - larvae[i]) - larvae;
            while (lower == i || lower == j)
                lower++;

            if (lower < lastIdx && larvae[lower] < larvae[i] + larvae[j])
                output = min(output, area(larvae[i], larvae[j], larvae[lower]));
        }
    }
    return (output == INT_MAX) ? -1.0 : sqrtl(output);
}

int main()
{
    cout << fixed << setprecision(10);
    int runs;
    cin >> runs;
    while (runs--)
    {
        int inputs;
        cin >> inputs;

        memset(larvae, -1, inputs * sizeof(int));

        REP(i, 0, inputs - 1)
        {
            ld in;
            cin >> in;
            larvae[i] = in;
        }
        sort(larvae, larvae + inputs);
        cout << solve(inputs - 1) << endl;
    }

    return 0;
}