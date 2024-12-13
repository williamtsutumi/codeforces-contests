#include <iostream>
#include <vector>

using namespace std;

#define ll long long

vector<ll> input;

ll solve()
{
    ll num = input[0];
    ll its = input.size();
    ll output = 0;
    for (ll i = 1; i < its; i++)
    {
        if (input[i] < num)
            output += num - input[i];
        else
            num = input[i];
    }
    return output;
}

int main()
{
    ll num_inputs;
    while (cin >> num_inputs)
    {
        input.resize(num_inputs);
        for (ll i = 0; i < num_inputs; i++)
        {
            ll in; cin >> in;
            input.at(i) = in;
        }
        cout << solve() << endl;
    }

    return 0;
}