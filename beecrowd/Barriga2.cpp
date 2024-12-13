#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

enum Cor
{
    AZUL,
    LARANJA,
    VERDE,
    VERMELHO,
};

struct Cylinder
{
    int height;
    int radious;
    Cor color;
};

int dp[1001][1001];
vector<Cylinder> cylinders;

bool myComp(Cylinder a, Cylinder b)
{
    return a.radious < b.radious;
}

// a embaixo de b
bool canStack(Cylinder a, Cylinder b)
{
    Cor corA = a.color;
    Cor corB = b.color;

    return (b.radious < a.radious
         && !((corA == LARANJA  && corB == VERMELHO)
           || (corA == AZUL     && corB == LARANJA)
           || (corA == VERDE    && corB == AZUL)
           || (corA == VERMELHO && corB == VERDE)));
}

int maxHeight(int idx, int prev)
{
    if (dp[idx + 1][prev + 1] != -1)
        return dp[idx + 1][prev + 1];

    if (idx == -1)
    {
        dp[idx + 1][prev + 1] = 0;
        return 0;
    }

    int naoColoca = maxHeight(idx - 1, prev);
    int coloca = -1;

    Cylinder atIdx = cylinders.at(idx);
    if (prev == -1 || canStack(cylinders.at(prev), atIdx))
        coloca = atIdx.height + maxHeight(idx - 1, idx);

    dp[idx + 1][prev + 1] = max(coloca, naoColoca);
    return dp[idx + 1][prev + 1];
}

int main()
{
    int numCylinders; cin >> numCylinders;
    while (numCylinders != 0)
    {
        memset(dp, -1, sizeof(int) * 1001 * 1001);
        cylinders.resize(numCylinders);

        for (int i = 0; i < numCylinders; i++)
        {
            int h, r; cin >> h >> r;
            string strCor; cin >> strCor;
            Cor cor;
            if (strCor == "AZUL")
                cor = AZUL;
            else if (strCor == "LARANJA")
                cor = LARANJA;
            else if (strCor == "VERDE")
                cor = VERDE;
            else if (strCor == "VERMELHO")
                cor = VERMELHO;

            cylinders.at(i) = Cylinder{h, r, cor};
        }
        sort(cylinders.begin(), cylinders.end(), myComp);
        cout << maxHeight(numCylinders - 1, -1) << " centimetro(s)" << endl;

        cin >> numCylinders;
    }
    return 0;
}