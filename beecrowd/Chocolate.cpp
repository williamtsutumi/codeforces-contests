#include <iostream>
#include <vector>

using namespace std;

int potencia;

string solve(int val)
{
    string base;
    while (val > 0)
    {
        base = to_string(val % potencia) + base;
        val /= potencia;
    }
    
    bool bMenosUm = false;
    for (int i = base.length() - 1; i >= 0; i--)
    {
        int digito = base[i] - '0';
        if (digito == potencia - 1)
        {
            bMenosUm = true;
            continue;
        }
        if (bMenosUm)
        {
            if (digito == potencia - 2)
                continue;
            else if (digito == 0)
            {
                bMenosUm = false;
                continue;
            }    
            else
                return "NO";
        }
        if (digito != 0 && digito != 1)
            return "NO";
    }

    return "YES";
}

int main()
{
    int numInput; cin >> numInput >> potencia;
    while (numInput--)
    {
        int val; cin >> val;
        cout << solve(val) << endl;
    }

    return 0;
}