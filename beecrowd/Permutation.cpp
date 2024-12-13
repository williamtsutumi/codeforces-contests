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

void solve(int col, vector<vi> &inputs, vi &output)
{
    int a, b, c, first;
    a = inputs[0][col];
    b = inputs[1][col];
    c = inputs[2][col];

    if (a == b)
        first = a;
    else if (a == c)
        first = a;
    else if (b == c)
        first = b;
        
    output.PB(first);

    if (inputs[0].size() - col <= 2)
    {
        int x, y, z, third, second;
        x = inputs[0][col + 1];
        y = inputs[1][col + 1];
        z = inputs[2][col + 1];

        if (x == y)
        {
            third = x;
            second = z;
        }
        else if (x == z)
        {
            third = x;
            second = y;
        }
        else if (y == z)
        {
            third = y;
            second = x;
        }
        output.PB(second);
        output.PB(third);
    }
    else
    {
        int aux = 0;
        auto lineToRemove = inputs.begin();
        while (inputs[aux][col] == first)
        {
            aux++;
            lineToRemove++;
        }

        inputs.erase(lineToRemove);

        solve(col + 1, inputs, output);
    }
}

int main()
{
    int runs; cin >> runs;
    while (runs--)
    {
        int numbers; cin >> numbers;

        vector<vi> inputs;
        inputs.resize(numbers);

        for (int i = 0; i < numbers; i++)
        {
            for (int j = 0; j < numbers - 1; j++)
            {
                int in; cin >> in;
                inputs[i].PB(in);
            }
        }

        vector<int> output;
        solve(0, inputs, output);


        cout << output[0];
        for (int i = 1; i < numbers; i++)
            cout << " " << output[i];
        cout << endl;
    }

    return 0;
}