#include <iostream>
#include <map>
#include <math.h>

using namespace std;

struct Ponto
{
    long long x;
    long long y;
};

long double dist(Ponto a, Ponto b)
{
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return sqrtl(dx * dx + dy * dy);
}

long long comb(long long n, long long p)
{
    long long out = 1;
    for (long long i = 0; i < p; i++)
    {
        out *= (n - i);
        out /= (i + 1);
    }
    return out;
}

long long solve(Ponto pontos[], long long numPontos)
{
    long long output = 0;
    for (long long i = 0; i < numPontos; i++)
    {
        map<long double, long long> mp;
        for (long long j = 0; j < numPontos; j++)
        {
            long double d = dist(pontos[i], pontos[j]);
            mp[d]++;
        }
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            if ((*it).second > 1)
            {
                output += comb((*it).second, 2);
            }
        }
    }
    return output;
}

int main()
{
    long long numPontos;
    while (cin >> numPontos)
    {
        if (numPontos == 0)
            break;
        Ponto pontos[numPontos];
        for (long long i = 0; i < numPontos; i++)
        {
            cin >> pontos[i].x >> pontos[i].y;
        }
        cout << solve(pontos, numPontos) << endl;
    }

    return 0;
}