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
typedef pair<int, int> pi;
const double INF = 1e9 + 7;

int mdc(int a, int b)
{
    if (b == 0)
        return a;

    return mdc(b, a % b);
}

ld dist(int dx, int dy)
{
    return sqrtl(dx * dx + dy * dy);
}

int solve(int l, int c, int min, int max)
{
    int output = 0;
    if (min <= 1)
    {
        // Contando linhas verticais e horizontais
        output += l * (c - 1) + c * (l - 1);
        // Contando linhas diagonais
        if (max >= 2)
            output += (l - 1) * (c - 1) * 2;
    }

    REP(i, 1, l)
    {
        REP(j, i + 1, c)
        {
            ld d = dist(i, j);
            if (mdc(i, j) == 1 && (min <= d && d <= max))
            {
                output += (l - i) * (c - j) * 2;

                if (i + 1 <= l && j + 1 <= c)
                    output += (c - i) * (l - j) * 2;
            }
        }
    }
    return output;
}

int main()
{
    int l, c, min, max;
    while (cin >> l >> c >> min >> max)
        cout << solve(l, c, min, max) % INF << endl;

    return 0;
}