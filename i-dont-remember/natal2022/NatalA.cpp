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

string board[8];

bool valid(int x, int y)
{
    return (0 <= x && x <= 7)
            && (0 <= y && y <= 7);
}

int numBombs(int i, int j)
{
    int output = 0;
    int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    REP (it, 0, 7)
    {
        int x = i + dx[it];
        int y = j + dy[it];
        if (valid(x, y) && board[x][y] == '*')
            output++;
    }
    return output;
}

void solve()
{
    REP (i, 0, 7)
    {
        REP (j, 0, 7)
        {
            if (board[i][j] == '.')
                board[i][j] = (char)numBombs(i, j) + '0';
        }
    }
}

int main()
{
    REP (i, 0, 7)
        getline(cin, board[i]);

    solve();

    REP (i, 0, 7)
        cout << board[i] << endl;

    return 0;
}