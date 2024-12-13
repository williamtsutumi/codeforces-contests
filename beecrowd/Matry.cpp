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

int solve(map<int, int> &mp)
{
    int output = 0;
    while (mp.size() != 0)
    {
        int start = mp.begin()->first;
        while (mp.count(start) > 0)
        {
            mp[start]--;
            if (mp[start] == 0) mp.erase(start);

            start++;
        }
        output++;
    }
    return output;
}

int solve2(map<int, int> &mp)
{
    int output = 0;
    while (mp.size() != 0)
    {
        int start = mp.begin()->first;
        int end = start;

        mp[start]--;
        if (mp[start] == 0) mp.erase(start);
        
        while (mp[start - 1] > 0)
        // while (mp.count(start - 1))
        {
            mp[start - 1]--;
            if (mp[start - 1] == 0) mp.erase(start - 1);

            start--;
        }
        while (mp[end + 1] > 0)
        // while (mp.count(end + 1))
        {
            mp[end + 1]--;
            if (mp[end + 1] == 0) mp.erase(end + 1);

            end++;
        }
        output++;
    }
    return output;
}

int main()
{
    int runs; cin >> runs;
    while (runs--)
    {
        map<int, int> mp;

        int inputs; cin >> inputs;
        for (int i = 0; i < inputs; i++)
        {
            int in; cin >> in;
            mp[in]++;
        }
        cout << solve2(mp) << endl;
    }

    return 0;
}