#include <iostream>
#include <vector>

using namespace std;

string solve(int pares, int impares)
{
    int modImpar = impares % 4;
    if (modImpar == 0)
        return "Alice";
    if (modImpar == 1)
    {
        if (pares % 2)
            return "Alice";
        else
            return "Bob";
    }
    if (modImpar == 2)
        return "Bob";
    if (modImpar == 3)
        return "Alice";

    return "Deu ruim";
}

int main()
{
    int runs;
    cin >> runs;
    while (runs--)
    {
        int numInputs;
        cin >> numInputs;
        int numPar = 0;
        int numImpar = 0;
        for (int i = 0; i < numInputs; i++)
        {
            int in;
            cin >> in;
            if (abs(in % 2) == 1)
                numImpar++;
            else
                numPar++;
        }
        cout << solve(numPar, numImpar) << endl;
    }

    return 0;
}