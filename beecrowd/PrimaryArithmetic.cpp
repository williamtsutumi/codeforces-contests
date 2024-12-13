#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PER(i, a, b) for (int i = a; i >= b; i--)
#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
const double INF = 1e9 + 7;

int solve(int n1, int n2)
{
    int digit_1, digit_2, output = 0;
    bool vai_um = false;
    while (n1 > 0 || n2 > 0)
    {
        digit_1 = n1 % 10, digit_2 = n2 % 10;

        if (digit_1 + digit_2 + (int)vai_um >= 10)
            output++, vai_um = true;
        else
            vai_um = false;

        n1 /= 10, n2 /= 10;
    }
    return output;
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    while (n1 || n2)
    {
        int sol = solve(n1, n2);
        if (sol == 0)
            cout << "No carry operation." << endl;
        else if (sol == 1)
            cout << sol << " carry operation." << endl;
        else
            cout << sol << " carry operations." << endl;

        cin >> n1 >> n2;
    }

    return 0;
}