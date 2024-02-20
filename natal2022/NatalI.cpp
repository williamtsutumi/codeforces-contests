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

int presentes[3000001];

int main()
{
    int presentes[childs + 1];

    int childs, rounds;
    cin >> childs >> rounds;

    for (int it = 0; it < rounds; it++)
    {
        int i, j;
        cin >> i >> j;

        if ((it % 2) == 0) // player1
        {
            for (int idx = i; idx <= j; idx++)
                presentes[idx] += idx - i + 1;
        }
        else // player2
        {
            for (int idx = i; idx <= j; idx++)
                presentes[idx] -= idx - i + 1;
        }
    }

    string output = "ALL I WANT FOR CHRISTMAS IS YOU";
    for (int i = 1; i < childs; i++)
    {
        if (presentes[i] < 0)
        {
            output = "UOY SI SAMTSIRHC ROF TNAW I LLA";
            break;
        }
    }
    cout << output << endl;

    return 0;
}