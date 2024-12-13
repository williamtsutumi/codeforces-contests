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

const string PI = "314159265358979323846264338327";

int solve(string input)
{
    int i = 0;
    while (i < 30 && PI[i] == input[i])
        i++;

    return i;
}

int main()
{
    int inputs; cin >> inputs;
    while (inputs--)
    {
        string in; cin >> in;
        cout << solve(in) << endl;
    }

    return 0;
}