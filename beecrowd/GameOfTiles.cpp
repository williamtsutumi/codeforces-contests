#include <iostream>
#include <string.h>

using namespace std;

int solve(char * game)
{
    return -1;
}

int main()
{
    int linhas, colunas; cin >> linhas >> colunas;
    char board[linhas + 1][colunas + 1];
    for (int i = 1; i <= linhas; i++)
    {
        string in; cin >> in;
        for (int j = 1; j <= colunas; j++)
        {
            board[i][j] = in[j - 1];
        }
    }
    for (int i = 1; i <= linhas; i++)
    {
        for (int j = 1; j <= colunas; j++)
        {
            if (board[i][j] == '.')
            {
                char game[linhas + 1][colunas + 1];
                memcpy(game, board, (linhas + 1) * (colunas + 1) * (sizeof(char)));
                cout << solve(game) << endl;
            }
        }
    }

    return 0;
}