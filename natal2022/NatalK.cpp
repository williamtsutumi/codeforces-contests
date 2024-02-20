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

ll solve(int in)
{
    int numLines = in * in;
    int sumLine = (numLines * (1 + numLines)) / 2;
    
    return sumLine * numLines;
}

int main()
{
    int inputs;
    cin >> inputs;

    for (int i = 0; i < inputs; i++)
    {
        int input;
        cin >> input;

        cout << solve(input) << endl;
    }

    return 0;
}