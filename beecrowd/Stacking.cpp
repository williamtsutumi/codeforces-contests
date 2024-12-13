#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
#include <set>
// https://www.beecrowd.com.br/judge/en/problems/view/1312
using namespace std;

struct Ball
{
    int linha;
    int coluna;
    int valor;
};

vector<Ball> balls;
int dp[1000];

int posToInt(Ball bola)
{
    return (((bola.linha - 1) * bola.linha) / 2) + bola.coluna - 1;
}

int retira(set<int> &retirados, Ball b)
{
    int pos = posToInt(b);
    // se b está no set
    if (retirados.find(pos) != retirados.end())
        return 0;

    int linha = b.linha;
    int coluna = b.coluna;
    int valor = b.valor;
    retirados.insert(pos);
    // primeira bola
    if (linha == 1 && coluna == 1)
        return b.valor;
    // ultima bola da linha
    else if (linha == coluna)
        return valor + retira(retirados, balls[pos - linha]);
    // primeira bola da linha
    else if (coluna == 1)
        return valor + retira(retirados, balls[pos - linha + 1]);
    // meio da linha
    else
        return valor + retira(retirados, balls[pos - linha + 1]) + retira(retirados, balls[pos - linha]);
}

int solve(set<int> r, int numBolas)
{
    // if (dp[numBolas] != 0)
    //     return dp[numBolas];
    if (numBolas == 0)
        return 0;

    int output;
    int naoTira = solve(r, numBolas - 1);
    int tira = retira(r, balls[numBolas - 1]) + solve(r, numBolas - 1);

    output = max(tira, naoTira);
    // dp[numBolas] = output;
    return output;
}

int main()
{
    int height;
    while (cin >> height)
    {
        balls.clear();
        memset(dp, 0, 1000 * sizeof(int));

        int linha = 1;
        for (int i = 1; i <= height; i++)
        {
            Ball bola;
            cin >> bola.valor;
            bola.linha = linha;
            bola.coluna = i;
            balls.push_back(bola);
            // Se tem que ir pra prox linha
            if (i == linha)
            {
                // Se é a última bola
                if (linha == height)
                    break;
                linha++;
                i = 0;
            }
        }
        // chamando solve para todas as bolas
        cout << to_string(solve(set<int> {}, balls.size())) << endl;
        // testando a func retira()
        // for (Ball b : balls)
        // {
        //     retirados.clear();
        //     cout << b.valor << endl;
        //     cout << retira(retirados, b) << endl << endl;
        // }
    }

    return 0;
}