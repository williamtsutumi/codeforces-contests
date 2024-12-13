#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int distancia[65];
queue<string> fila;
vector<vector<string>> grafo;

vector<string> movimentos(string pos)
{
    vector<string> resultado = {};
    char movLinha[8] = {1, -1, 1, -1, 2, -2, 2, -2};
    char movColuna[8] = {2, 2, -2, -2, 1, 1, -1, -1};

    for (int i = 0; i < 8; i++)
    {
        int coluna = pos[0] + movColuna[i];
        int linha = pos[1] + movLinha[i];
        if ('1' <= linha && linha <= '8' && 'a' <= coluna && coluna <= 'h')
        {
            string move = "";
            move += coluna;
            move += linha;
            resultado.push_back(move);
        }
    }
    return resultado;
}

int moveToInt(string move)
{
    return (move[0] - 'a') + (move[1] - '1') * 8;
}

int bfs(string from, string to)
{
    if (from == to)
        return 0;

    distancia[moveToInt(from)] = 0;
    fila.push(from);
    while (!fila.empty())
    {
        from = fila.front();
        fila.pop();

        int fromInt = moveToInt(from);
        for (string move : grafo[fromInt])
        {
            // Se a distancia nao foi calculada, calule e coloca mov na fila
            // caso contratio, nao faça nada.
            if (distancia[moveToInt(move)] == -1)
            {
                distancia[moveToInt(move)] = distancia[fromInt] + 1;
                fila.push(move);
            }
        }
    }
    return distancia[moveToInt(to)];
}

int main()
{
    // pré processamento
    grafo.resize(64);
    for (char coluna = 'a'; coluna <= 'h'; coluna++)
    {
        for (char linha = '1'; linha <= '8'; linha++)
        {
            string pos = "";
            pos += coluna;
            pos += linha;
            for (string mov : movimentos(pos))
            {
                grafo[moveToInt(pos)].push_back(mov);
            }
        }
    }
    // printa grafo
    // for (int i = 0; i < 64; i++)
    // {
    //     cout << "pos: " << i << endl;
    //     for (int j = 0; j < grafo[i].size(); j++)
    //     {
    //         cout << "valor: " << grafo[i][j] << endl;
    //     }
    // }
    string from, to;
    vector<int> output = {};
    vector<string> input = {};
    // entrada
    while (cin >> from >> to)
    {
        input.push_back(from);
        input.push_back(to);
    }
    // processamento
    for (int i = 0; i < input.size(); i += 2)
    {
        while (!fila.empty())
            fila.pop();

        memset(distancia, -1, 65 * sizeof(bool));
        output.push_back(bfs(input[i], input[i + 1]));
    }
    // saida
    for (int i = 0; i < input.size(); i += 2)
    {
        cout << "To get from " << input[i] << " to " << input[i + 1] << " takes " << to_string(output[i / 2]) << " knight moves." << endl;
    }

    return 0;
}

// int bfs(string from, string to)
// {
//     if (from == to)
//         return 0;

//     inqueue.push(from);
//     dist[c2i(from)] = 0;
//     int out = -1;

//     while (!inqueue.empty())
//     {
//         string processing = inqueue.front();
//         inqueue.pop();
//         for (string neighbour : grafo[c2i(processing)])
//         {
//             if (visited[c2i(neighbour)])
//                 continue;
//             visited[c2i(neighbour)] = true;
//             inqueue.push(neighbour);
//             dist[c2i(neighbour)] = dist[c2i(processing)] + 1;
//             if (neighbour == to)
//                 out = dist[c2i(neighbour)];
//         }
//     }
//     return out;
// }