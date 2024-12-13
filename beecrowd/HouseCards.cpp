#include <iostream>
#include <math.h>

using namespace std;

#define ll long long

ll cartas(ll altura)
{
    return (3 * altura + 1) * altura / 2;
}

ll solve(ll in, ll from, ll to)
{
    // cout << "****************\n";
    // cout << in << endl;
    // cout << from << endl;
    // cout << to << endl << endl;

    ll meio = (from + to) / 2;
    ll cMeio = cartas(meio);

    if (cMeio == in || (cMeio < in && in < cartas(meio + 1)))
        return meio;
    else if (cMeio < in)
        return solve(in, meio + 1, to);
    else
        return solve(in, from, meio);
}

int main()
{
    ll numInputs; cin >> numInputs;
    while (numInputs--)
    {
        ll in; cin >> in;
        cout << solve(in, 0, 1000000000) << endl;
    }

    return 0;
}