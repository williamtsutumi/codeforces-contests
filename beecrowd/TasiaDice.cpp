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

void solve(int dices, int sumBefore, int sumAfter, vector<int> &output)
{
    int maxDice = sumBefore - sumAfter;
    int sumOutput = dices * maxDice;

    for (int i = 0; i < dices; i++)
        output.PB(maxDice);

    int aux = maxDice - 1;
    int idx = 0;
    while (sumOutput - sumBefore > aux)
    {
        output[idx] = 1;
        idx++;
        sumOutput -= aux;
    }
    if (sumOutput > sumBefore)
    {
        output[idx] = maxDice - (sumOutput - sumBefore);
    }

}

int main()
{
    int inputs;
    cin >> inputs;
    while (inputs--)
    {
        int dices, sumBefore, sumAfter;
        cin >> dices >> sumBefore >> sumAfter;

        vector<int> output;
        solve(dices, sumBefore, sumAfter, output);

        cout << output[0];
        for (int i = 1; i < output.size(); i++)
            cout << " " << output[i];
        cout << endl;
    }

    return 0;
}