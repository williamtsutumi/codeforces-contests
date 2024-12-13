#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long combinacao(long long n, long long p)
{
    if (p > n)
        return 0;

    if (p > n - p)
        p = n - p;

    long long out = 1;
    long long aux = 1;
    long long i = n;
    while (i > n - p)
    {
        out *= i;
        if (out % aux == 0 && aux <= p)
        {
            out /= aux;
            aux++;
        }
        i--;
    }
    while (aux <= p)
    {
        out /= aux;
        aux++;
    }
    return out;
}

bool myComp(long long a, long long b)
{
    return a > b;
}

long long solve(vector<long long> caixas, long long idx, long long toChoose, long long pesoMax)
{
    if (toChoose == 0)
        return 1;
    if (idx == caixas.size())
        return 0;

    long long maior = caixas.at(idx);

    if (maior > pesoMax)
        return solve(caixas, idx + 1, toChoose, pesoMax);

    long long naoEscolhe = combinacao(caixas.size() - idx - 1, toChoose);
    long long escolhe = solve(caixas, idx + 1, toChoose - 1, pesoMax - maior);

    return escolhe + naoEscolhe;
}
/*
3 2
10 1 3
4 13
out: 3

4 3
20 10 50 1
21 81
out: 4

6 3
14 70 3 1 6 31
10 74
out: 11

4 2
1 4 8 15
10 23
*/

int main()
{
    long long numCaixas, toChoose;
    cin >> numCaixas >> toChoose;
    vector<long long> caixas;
    while (numCaixas--)
    {
        long long c;
        cin >> c;
        caixas.push_back(c);
    }
    long long pesoMin, pesoMax;
    cin >> pesoMin >> pesoMax;

    sort(caixas.begin(), caixas.end(), myComp);
    long long m = solve(caixas, 0, toChoose, pesoMax);
    long long n = solve(caixas, 0, toChoose, pesoMin - 1);

    long long out = m - n;
    cout << out << endl;

    return 0;
}