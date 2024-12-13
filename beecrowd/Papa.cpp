#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

struct Caixa
{
    int peso;
    int resistencia;
};

vector<Caixa> caixasG;

bool canStack(vector<Caixa> empilhadas, int pos, Caixa c)
{
    empilhadas.insert(empilhadas.begin() + pos, c);

    int pesoTotal = 0;
    for (Caixa emp : empilhadas)
        pesoTotal += emp.peso;

    for (int i = 0; i <= pos; i++)
    {
        Caixa emp = empilhadas.at(i);
        pesoTotal -= emp.peso;
        if (emp.resistencia < pesoTotal)
            return false;
    }
    return true;
}

int solve(vector<Caixa> caixas, vector<Caixa> emp, int numCaixas)
{
    if (numCaixas == 0)
        return 0;

    int output = 0;
    for (int i = 0; i < caixas.size(); i++)
    {
        Caixa c = caixas.at(i);
        for (int j = 0; j <= emp.size(); j++)
        {
            if (canStack(emp, j, c))
            {
                int naoColoca = solve(caixas, emp, numCaixas - 1);
                int coloca = put(i, caixas, j, emp, c, numCaixas - 1);

                output = max(coloca, naoColoca);
            }
        }
    }
    return output;
}

int put(int posToRemove, vector<Caixa> caixas, int posToEmp, vector<Caixa> emp, Caixa toEmp, int numCaixas)
{
    caixas.erase(caixas.begin() + posToRemove);
    emp.insert(emp.begin() + posToEmp, toEmp);

    return solve(caixas, emp, numCaixas - 1);
}

int main()
{
    int numCaixas;
    cin >> numCaixas;
    int peso, r;
    while (cin >> peso >> r)
    {
        if (r - peso >= 0)
            caixasG.push_back(Caixa{peso, r - peso});
    }
    cout << solve(caixasG, {}, caixasG.size()) << endl;

    return 0;
}