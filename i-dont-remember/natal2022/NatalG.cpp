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

struct Ornament
{
    string name;
    int price;
    int rate;
};

bool myComp(Ornament a, Ornament b)
{
    if (a.price == b.price)
        return a.rate > b.rate;

    return a.price < b.price;
}

int main()
{
    int inputs, budget;
    cin >> inputs >> budget;

    vector<Ornament> ornaments;
    ornaments.resize(inputs);

    for (int i = 0; i < inputs; i++)
    {
        string name;
        cin >> name;
        int price, rate;
        cin >> price >> rate;

        ornaments[i] = Ornament{name, price, rate};
    }
    
    sort(ornaments.begin(), ornaments.end(), myComp);

    int totalPrice = 0;
    for (int i = 0; true; i++)
    {
        totalPrice += ornaments[i].price;
        if (totalPrice > budget)
            break;

        cout << ornaments[i].name << endl;
    }

    return 0;
}