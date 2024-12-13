#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int ordenaLinha(vector<int> &containers, int valorInicial)
{
    int out = 0;
    int size = containers.size();
    for (int i = 0; i < size; i++)
    {
        // Se não está na posição correta
        if (containers[i] != valorInicial + i)
        {
            // Encontra a posição correta
            auto pos = find(containers.begin(), containers.end(), valorInicial + i);
            int idx = pos - containers.begin();
            // Fazendo a troca entre os elementos
            int aux = containers[idx];
            containers[idx] = containers[i];
            containers[i] = aux;

            out++;
        }
    }

    return out;
}

string solve(vector<vector<int>> &containers, int row, int col)
{
    if (row == 1 && col == 1)
        return "0";

    for (int i = 0; i < row; i++)
    {
        int max = containers[i][0];
        int min = containers[i][0];
        for (int j = 1; j < col; j++)
        {
            int pos = containers[i][j];
            if (pos > max)
                max = pos;
            else if (pos < min)
                min = pos;
        }
        if (max - min >= col)
            return "*";
    }

    for (int j = 0; j < col - 1; j++)
    {
        int firstDiff = containers[0][j] - containers[0][j + 1];
        for (int i = 0; i < row; i++)
        {
            int atual = containers[i][j];
            int prox = containers[i][j + 1];
            if (atual - prox != firstDiff)
                return "*";
        }
    }
    // Falha com uma linha ou uma coluna, trata separadamente
    if (row == 1)
        return to_string(ordenaLinha(containers[0], 1));

    if (col == 1)
    {
        vector<int> coluna;
        for (int i = 0; i < row; i++)
        {
            coluna.push_back(containers[i][0]);
        }
        return to_string(ordenaLinha(coluna, 1));
    }
    // Fazendo a ordenacao da primeira linha
    int minLinhaUm = containers[0][0];
    for (int i = 0; i < col; i++)
    {
        if (containers[0][i] < minLinhaUm)
            minLinhaUm = containers[0][i];
    }
    int output = ordenaLinha(containers[0], minLinhaUm);
    // Fazendo a ordencao da primeira coluna
    vector<int> firstCol;
    for (int i = 0; i < row; i++)
        firstCol.push_back((containers[i][0] - 1) / col);

    output += ordenaLinha(firstCol, 0);

    return to_string(output);
}

int main()
{
    int row, col;
    while (cin >> row >> col)
    {
        vector<vector<int>> containers;
        containers.resize(row);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int in;
                cin >> in;
                containers.at(i).push_back(in);
            }
        }
        cout << solve(containers, row, col) << endl;
    }

    return 0;
}