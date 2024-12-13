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



int main()
{
    int in, in_size; cin >> in >> in_size;

    map<string, int> mp;
    while (in--)
    {
        string p; cin >> p;
        int idx = p.find('*');
        for (char i = 'a'; i <= 'z'; i++)
        {
            p[idx] = i;
            mp[p]++;
        }
    }
    pair<string, int> output;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if ((*it).second > output.second)
        {
            output.first = (*it).first;
            output.second = (*it).second;
        }
    }
    cout << output.first << " " << output.second << endl;

    return 0;
}