#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>

using namespace std;

int numHoles, circ, patch1, patch2;
vector<int> holes;
int dp[1000][1000];

// Retorna o primeiro indice de "holes" que "patch" não cobre mais
int idxPatch(int patch, int idx, int from, bool &acabou)
{
    int dist = 0;
    int proxDist = 0;
    int size = holes.size();
    int lastIdx = size - 1;

    while (dist + proxDist <= patch)
    {
        dist += proxDist;

        if (acabou && idx == from)
        {
            break;
        }
        else if (idx == 0)
        {
            proxDist = circ - holes[lastIdx] + holes[0];
            idx = lastIdx;
            acabou = true;
        }
        else
        {
            proxDist = holes[idx] - holes[idx - 1];
            idx--;
        }
    }
    return idx;
}

int solve(int idx, int from, bool &acabou)
{
    if (dp[idx][from] != -1)
        return dp[idx][from];

    if (acabou && idx == from)
        return 0;
    
    int idxP1 = idxPatch(patch1, idx, from, acabou);
    int coloca1 = patch1 + solve(idxP1, from, acabou);

    bool aux = false;
    int idxP2 = idxPatch(patch2, idx, from, aux);
    int coloca2 = patch2 + solve(idxP2, from, aux);

    dp[idx][from] = min(coloca1, coloca2);
    return dp[idx][from];
}

int main()
{
    while (cin >> numHoles >> circ >> patch1 >> patch2)
    {
        memset(dp, -1, sizeof(int) * 1000 * 1000);
        holes.resize(numHoles);

        for (int i = 0; i < numHoles; i++)
        {
            int hole;
            cin >> hole;
            holes.at(i) = hole;
        }
        int lastIdx = holes.size() - 1;
        bool acabou = false;
        cout << solve(lastIdx, lastIdx, acabou) << endl;
    }

    return 0;
}