#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int dp[200000][2];

// int solve(vector<int> &input, int i, int j, bool colocouI, bool colocouJ)
// {
//     if (i == j)
//         return input[i];

//     int colocaDir = input[j] + solve(input, i, j - 1, colocouI, true);
//     int colocaEsq = input[i] + solve(input, i + 1, j, true, colocouJ);

//     int naoColocaEsq = INT_MIN;
//     int naoColocaDir = INT_MIN;
//     if (!colocouI)
//         naoColocaEsq = solve(input, i + 1, j, colocouI, colocouJ);
//     if (!colocouJ)
//         naoColocaDir = solve(input, i, j - 1, colocouI, colocouJ);

//     int naoColoca = max(naoColocaEsq, naoColocaDir);
//     int coloca = max(colocaEsq, colocaDir);

//     return max(coloca, naoColoca);
// }

// int botUp[200000][18];
// bottom up
int solve(vector<int> &sums, int numInput)
{
    for (int i = 3; i <= numInput; i++)
    {
        for (int j = 0; j <= numInput - i; j++)
        {
            int mod = i % 2;
            int maxAnt = max(dp[j][mod], dp[j + 1][mod]);
            dp[j][!mod] = max(maxAnt, sums[i + j] - sums[j]);
        }
    }
    return dp[0][!(numInput%2)];
}

int main()
{
    int numInput;
    while (cin >> numInput)
    {
        vector<int> sums;
        sums.resize(numInput + 1);

        int in; cin >> in;
        sums[0] = 0;
        sums[1] = in;
        dp[0][0] = in;
        for (int i = 1; i < numInput; i++)
        {
            cin >> in;
            dp[i][0] = in;
            dp[i - 1][1] = max(dp[i][0], dp[i - 1][0]);
            sums[i + 1] = sums[i] + in;
        }
        cout << solve(sums, numInput) << endl;
    }

    return 0;
}