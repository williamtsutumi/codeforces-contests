#include <iostream>
#include <limits.h>

using namespace std;

int ordemMatriz;
int xTorre;
int yTorre;
int toPaint;

int soma_pa_razao1(int n)
{
    return ((n + 1) * n) / 2;
}

int soma_pa_razao2(int n)
{
    return n * n;
}

int solve()
{
    int i = 0;
    int totalPintados = 1;
    while (totalPintados < toPaint)
    {
        cout << "i: " << i << endl;
        totalPintados = 4 * soma_pa_razao1(i) + 1;
        cout << "total pintados: " << totalPintados << endl;

        int esq = xTorre - i;
        int dir = xTorre + i;
        int cima = yTorre - i;
        int baixo = yTorre + i;
        int saindoDir = dir - ordemMatriz;
        int saindoBaixo = baixo - ordemMatriz;
        int overlap;

        if (saindoDir > ordemMatriz - xTorre && saindoBaixo > ordemMatriz - yTorre)
        {
            overlap = (saindoDir + saindoBaixo - 2 * ordemMatriz - 2 + xTorre + yTorre) / 2;
            cout << "overlap: " << overlap << endl;
            totalPintados += soma_pa_razao1(overlap);
        }
        if (cima <= 0)
        {
            int aux = dir + baixo + 2 - (2 * ordemMatriz);
            cout << aux << endl;
            totalPintados -= soma_pa_razao2(-cima);
        }
        if (saindoBaixo > 0)
        {
            cout << "saindo baixo: " << saindoBaixo << endl;
            totalPintados -= soma_pa_razao2(saindoBaixo);
        }
        if (esq <= 0)
        {
            totalPintados -= soma_pa_razao2(-esq);
        }
        if (saindoDir)
        {
            cout << "saindo dir: " << saindoDir << endl;
            totalPintados -= soma_pa_razao2(saindoDir);
        }
        i++;
        cout << "pintados: " << totalPintados << endl;
    }
    return i - 1;
}

int main()
{
    cin >> ordemMatriz >> xTorre >> yTorre >> toPaint;
    cout << solve() << endl;

    return 0;
}