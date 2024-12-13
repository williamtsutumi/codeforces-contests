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

vector<vi> tree;

int maxHeight(vi node)
{
    if (node.size() == 0)
        return 1;

    int output = INT_MIN;
    for (int child : node)
        output = max(output, maxHeight(tree[child]));

    return 1 + output;
}

int solve()
{
    int output = 0;
    for (int node = 0; node < tree.size(); node++)
    {
        int max1 = 0, max2 = 0;
        for (int child : tree[node])
        {
            int h = maxHeight(tree[child]);

            if (h >= max1)
                max2 = max1, max1 = h;
            else if (h > max2)
                max2 = h;
        }
        output = max(output, max1 + max2 + 1);
    }
    return output;
}

int main()
{
    int nodes;
    cin >> nodes;
    tree.resize(nodes);
    while (--nodes)
    {
        int from, to;
        cin >> from >> to;
        tree[from - 1].push_back(to - 1);
    }
    cout << solve() - 1 << endl;

    return 0;
}