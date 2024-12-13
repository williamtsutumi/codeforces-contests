#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<pair<int, int>> vet;

    int l, c;
    bool primeiro = true;
    while (cin >> l >> c)
    {
        vet.clear();
        if (!primeiro)
            cout << endl;
        primeiro = false;
        int mapa[l + 1][c + 1];
        for (int i = 1; i <= l; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                cin >> mapa[i][j];
            }
        }
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        bool temPico = false;
        for (int i = 1; i <= l; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                bool pico = true;
                for (int k = 0; k < 8; k++)
                {
                    if (1 <= i + dx[k] && i + dx[k] <= l
                        && 1 <= j + dy[k] && j + dy[k] <= c)
                    {
                        if (mapa[i + dx[k]][j + dy[k]] >= mapa[i][j])
                            pico = false;
                    }
                }
                if (pico)
                {
                    temPico = true;
                    pair<int, int> par(i, j);
                    vet.push_back(par);
                }
            }
        }
        if (!temPico)
            cout << -1 << endl;

        sort(vet.begin(), vet.end());
        for (pair<int, int> p : vet)
        {
            cout << p.first << " " << p.second << endl;
        }
    }
    cout << endl;

    return 0;
}