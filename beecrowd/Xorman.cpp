#include <iostream>
#include <math.h>

using namespace std;

long long solve(long long a, long long b)
{
    string bitsA;
    long long aux = a;
    while (aux > 0)
    {
        bitsA = to_string(aux % 2) + bitsA;
        aux /= 2;
    }

    string output;
    long long outputDec = 0;
    for (long long i = 0; i < bitsA.size(); i++)
    {
        if (bitsA[i] == '1')
        {
            output = "0" + output;
        }
        else
        {
            long long pot = pow(2, bitsA.size() - 1 - i);
            if (outputDec + pot > b)
            {
                output = "0" + output;
            }
            else
            {
                outputDec += pot;
                output = "1" + output;
            }
        }
    }
    outputDec = outputDec ^ a;
    return outputDec;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << max(solve(a, b), solve(b, a)) << endl;

    return 0;
}