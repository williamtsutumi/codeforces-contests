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

int solve(string in)
{
    map<int, int> first, last;
    for (int i = 0; i < in.size(); i++)
    {
        if (first.count(in[i]) == 0)
            first[in[i]] = i;
    }
    for (int i = in.size() - 1; i > 0; i--)
    {
        if (last.count(in[i]) == 0)
            last[in[i]] = i;
    }
    
    int aux = 0;
    int maxAux = 0;
    for (int i = 0; i < in.size(); i++)
    {
        int key = in[i];
        
        if (last[key] != first[key] && first[key] == i)
        {
            aux++;
            if (aux > maxAux)
                maxAux = aux;
        }
        else if (last[key] != first[key] && last[key] == i)
            aux--;
    }
    return first.size() + maxAux;
}

int main()
{
    int runs; cin >> runs;
    while (runs--)
    {
        int len; cin >> len;

        string in; cin >> in;
        cout << solve(in) << endl;
    }

    return 0;
}