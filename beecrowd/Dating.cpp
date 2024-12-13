#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>
//https://www.beecrowd.com.br/judge/en/problems/view/2348
using namespace std;

long double PI = 3.14159265359;

bool myComp(int a, int b)
{
    return a > b;
}

long double solve(int valores[], int n)
{
    long double seno = sin(2 * PI / n);
    sort(valores, valores + n, myComp);
    long double out = 0;
    int aux[n];
    for (int i = 0; i < n; i++)
    {
        int pos;
        if (i % 2 == 0)
            pos = i / 2;
        else
            pos = n - 1 - i / 2;
        aux[pos] = valores[i];
        // aux[i / 2] = valores[i];
        // aux[(n - 1 - (i / 2))] = valores[i + 1];
    }
    for (int i = 0; i < n - 1; i++)
    {
        out += aux[i] * aux[i + 1] / 2.0;
    }
    out += aux[0] * aux[n - 1] / 2.0;

    return out * seno;
}

int main()
{
    int n; cin >> n;
    int valores[n];
    for (int i = 0; i < n; i++)
    {
        cin >> valores[i];
    }
    cout << fixed << setprecision(3) << solve(valores, n) << endl;

    return 0;
}