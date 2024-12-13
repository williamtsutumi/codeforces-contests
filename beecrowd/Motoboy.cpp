#include <iostream>
#include <string.h>
#include <limits.h>

using namespace std;

struct Order
{
    int tempo;
    int pizzas;
};

Order orderArr[21];
// dp[i][j] == maior tempo que leva para fazer as entregas,
// entregando até i pizzas e as j primeiras pizzas que foram digitadas
int dp[31][21];

int tempoMax(int idx, int maxPizzas)
{
    // Memoização
    if (dp[maxPizzas][idx] != -1)
        return dp[maxPizzas][idx];
    // Caso base
    if (maxPizzas == 0 || idx == 0)
        return 0;

    int pizzas = orderArr[idx].pizzas;

    int naoEntrega = tempoMax(idx - 1, maxPizzas);

    int entrega = INT_MIN;
    if (pizzas > maxPizzas)
        entrega = orderArr[idx].tempo + tempoMax(idx - 1, maxPizzas - pizzas); 
    // Em vez de só retornar, armazena
    int result = max(entrega, naoEntrega);
    dp[maxPizzas][idx] = result;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numOrders, maxPizzas;
    while (cin >> numOrders >> maxPizzas)
    {
        memset(dp, -1, 31 * 21 * sizeof(int));
        for (int i = 1; i <= numOrders; i++)
        {
            cin >> orderArr[i].tempo >> orderArr[i].pizzas;
        }
        cout << tempoMax(numOrders, maxPizzas) << " min." << endl;
    }

    return 0;
}