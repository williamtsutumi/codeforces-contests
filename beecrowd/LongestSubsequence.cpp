#include <iostream>
#include <vector>
#include <cstring>
#include <deque>

using namespace std;

deque<int> output;
int dp[1000][1000];

// Top-down
int lcs(vector<int> &x, vector<int> &y, int sizeX, int sizeY)
{
    if (dp[sizeX][sizeY] != -1)
        return dp[sizeX][sizeY];

    if (sizeX == 0 || sizeY == 0)
        return 0;

    if (x[sizeX - 1] == y[sizeY - 1])
        dp[sizeX][sizeY] = 1 + lcs(x, y, sizeX - 1, sizeY - 1);
    else
        dp[sizeX][sizeY] = max(lcs(x, y, sizeX, sizeY - 1), lcs(x, y, sizeX - 1, sizeY));

    return dp[sizeX][sizeY];
}

// Bottom-up
int lcs_botup(vector<int> &x, vector<int> &y)
{
    int i, j;
    int sizeX = x.size();
    int sizeY = y.size();
    // solução
    for (i = 1; i <= sizeX; i++)
        dp[i][0] = 0;

    for (j = 0; j <= sizeY; j++)
        dp[0][j] = 0;

    for (i = 1; i <= sizeX; i++)
    {
        for (j = 1; j <= sizeY; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // armazenando a subsequencia
    i = sizeX, j = sizeY;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            output.push_front(x[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    return dp[sizeX][sizeY];
}

int main()
{
    char input;
    int sizeX, sizeY;
    cin >> sizeX >> sizeY;
    vector<int> x, y;

    memset(dp, -1, 1000 * 1000 * sizeof(int));
    x.resize(sizeX);
    y.resize(sizeY);

    for (int i = 0; i < sizeX; i++)
    {
        cin >> input;
        x[i] = input;
    }
    for (int i = 0; i < sizeY; i++)
    {
        cin >> input;
        y[i] = input;
    }

    cout << lcs_botup(x, y) << endl;

    for (char c : output)
        cout << c;
    cout << endl;
    return 0;
}