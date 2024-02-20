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
        int len, coins; cin >> len >> coins;
        
        vector<int> costs(len + 1);
        for (int i = 1; i <= len; i++)
        {
            int in; cin >> in;
            costs[i] = in + i;
        }
        sort(costs.begin(), costs.end());

        int spent = 0;
        int output = 0;
        for (int i = 1; i <= len; i++)
        {
            spent += costs[i];

            if (spent > coins)
                break;

            output++;
        }
        cout << output << endl;
    }

    return 0;
}