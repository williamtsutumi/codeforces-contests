#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

typedef long long ll;

ll solve(vector<ll> &input, ll numInput)
{
    ll output = INT_MIN, sum = 0;
    for (ll i = 0; i < numInput; i++)
    {
        sum = max(input[i], sum + input[i]);
        output = max(output, sum);
    }
    return output;
}

int main()
{
    ll numInput;
    while (cin >> numInput)
    {
        vector<ll> input;
        input.resize(numInput);
        for (ll i = 0; i < numInput; i++)
        {
            ll in; cin >> in;
            input[i] = in;
        }
        cout << solve(input, numInput) << endl;
    }

    return 0;
}