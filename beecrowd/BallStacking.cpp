#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct Ball
{
    int x;
    int y;
    int value;
};

vector<Ball> balls;

// retorna a soma que retirar "bola" causa, dadas as que já foram retiradas
int retira(set<int> &retiradas, int bolaIdx)
{
    if (retiradas.find(bolaIdx) != retiradas.end())
        return 0;

    retiradas.insert(bolaIdx);
    if (bolaIdx == 0)
        return balls.at(0).value;

    Ball bola = balls.at(bolaIdx);
    int out = bola.value;
    int esq = bolaIdx - bola.y;
    int dir = esq + 1;
    // primeira bola da linha
    if (bola.x == 1)
        out += retira(retiradas, dir);
    // última bola da linha
    else if (bola.x == bola.y)
        out += retira(retiradas, esq);
    // qualquer outra bola
    else
        out += retira(retiradas, dir) + retira(retiradas, esq);

    return out;
}

int solve(set<int> retiradas, int numBalls)
{
    if (numBalls == 0)
        return 0;

    int naoTira = solve(retiradas, numBalls - 1);
    int tira = retira(retiradas, numBalls - 1) + solve(retiradas, numBalls - 1);

    return max(tira, naoTira);
}

int main()
{
    int height;
    while (cin >> height)
    {
        balls.clear();

        int yAux = 1;
        for (int i = 1; i <= height; i++)
        {
            Ball b;
            cin >> b.value;
            b.x = i;
            b.y = yAux;
            balls.push_back(b);
            // se tem que ir pro prox y
            if (yAux == i)
            {
                // se foi a ultima bola
                if (yAux == height)
                    break;
                i = 0;
                yAux++;
            }
        }
        cout << solve({}, balls.size()) << endl;
    }
}