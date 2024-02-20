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
    string toCheck = "merrychristmasMERRYCHRISTMAS";

    int magazines;
    map<int, int> mp;
    while (cin >> magazines)
    {
        for (int its = 0; its < magazines; its++)
        {
            int texts;
            cin >> texts;

            string line;
            getline(cin, line);
            for (int i = 0; i < texts; i++)
            {
                getline(cin, line);
                for (char c : line)
                {
                    if (toCheck.find(c) != string::npos)
                        mp[tolower(c)]++;
                }
            }
        }
    }

    int output = INT_MAX;
    for (auto &[key, val] : mp)
    {
        if (key == 'r')
            output = min(output, val / 3);
        else if (key == 's')
            output = min(output, val / 2);
        else
            output = min(output, val);
    }
    cout << output << endl;

    return 0;
}