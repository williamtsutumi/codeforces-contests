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
        int inputs; cin >> inputs;

        pair<int, int> pos = make_pair(0, 0);
        bool aux = true;
        string in; cin >> in;
        for (int j = 0; j < in.size(); j++)
        {
            if (in[j] == 'U')
                pos.second++;
            else if (in[j] == 'D')
                pos.second--;
            else if (in[j] == 'L')
                pos.first--;
            else if (in[j] == 'R')
                pos.first++;
                
            if (pos.first == 1 && pos.second == 1)
            {
                cout << "YES" << endl;
                aux = false;
                break;
            }
        }
        if (aux)
            cout << "NO" << endl;
    }

    return 0;
}