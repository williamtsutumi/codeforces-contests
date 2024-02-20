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

struct Child
{
    string name, region;
    int dist;
};

bool myComp(Child a, Child b)
{
    if (a.region != b.region)
        return a.region < b.region;

    if (a.dist != b.dist)
        return a.dist < b.dist;

    return a.name < b.name;
}

int main()
{
    int inputs;
    cin >> inputs;

    Child childs[inputs];

    for (int i = 0; i < inputs; i++)
    {
        string name, region;
        cin >> name >> region;

        int dist;
        cin >> dist;

        childs[i] = Child{name, region, dist};
    }

    sort(childs, childs + inputs, myComp);
    for (int i = 0; i < inputs; i++)
        cout << childs[i].name << endl;

    return 0;
}