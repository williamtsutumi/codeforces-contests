#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int jogadores;
    cin >> jogadores;
    int jogadores_aux = jogadores;

    bool vivos[jogadores];
    memset(vivos, true, sizeof(bool) * jogadores);

    int toKill = 1;
    while (jogadores > 1)
    {
        int its = (jogadores + 1) / 2;
        while (its--)
        {
            // Encontrando o próximo vivo (que será morto)
            while (!vivos[toKill])
                toKill = (toKill + 1) % jogadores_aux;

            vivos[toKill] = false;
            cout << toKill + 1 << endl;
            // Encontrando o próximo vivo (que irá matar)
            int nextAlive = (toKill + 1) % jogadores_aux;

            while (!vivos[nextAlive])
                nextAlive = (nextAlive + 1) % jogadores_aux;

            toKill = (nextAlive + 1) % jogadores_aux;
        }
        jogadores /= 2;
    }
    for (int i = 0; i < jogadores_aux; i++)
    {
        if (vivos[i])
            cout << i + 1 << endl;
    }
    // while (vivos.size() > 0)
    // {
    //     int size = vivos.size();
    //     int its = size / 2;
    //     for (int i = 1; i <= its; i++)
    //     {
    //         cout << vivos.at(i) << endl;
    //         vivos.erase(vivos.begin() + i);
    //     }
    //     if (size % 2)
    //     {
    //         cout << vivos.at(0) << endl;
    //         vivos.erase(vivos.begin());
    //     }
    //     // vivos.erase(vivos.begin() + 1 -0); // 2
    //     // vivos.erase(vivos.begin() + 3 -1); // 4
    //     // vivos.erase(vivos.begin() + 5 -2); // 6
    // }

    return 0;
}