#include <iostream>
#include <map>

using namespace std;

map<int, int> mp;
int joao = 0;
int maria = 0;

int solve()
{
    int mariaGanha = 23 - maria;
    int joaoEstoura = 24 - joao;

    if (joaoEstoura > 10 && mariaGanha > 10)
        return -1;

    if (mariaGanha > 10)
        return -1;

    if (joaoEstoura < mariaGanha)
    {
        while (mp[joaoEstoura] == 4)
            joaoEstoura++;

        if (joaoEstoura > 13)
            return -1;
        
        if (mp[mariaGanha] == 4)
            return joaoEstoura;
        
        return min(mariaGanha, joaoEstoura);
    }
    else
    {
        if (mp[mariaGanha] == 4)
            return -1;

        return mariaGanha;
    }
}

int main()
{
    int numRodadas;
    while (cin >> numRodadas)
    {
        mp.clear();
        joao = 0;
        maria = 0;
        int inicial;
        cin >> inicial; joao += inicial;
        mp[inicial]++;
        cin >> inicial; joao += inicial;
        mp[inicial]++;

        cin >> inicial; maria += inicial;
        mp[inicial]++;
        cin >> inicial; maria += inicial;
        mp[inicial]++;

        for (int i = 0; i < numRodadas; i++)
        {
            int r; cin >> r;
            mp[r]++;

            if (r > 10)
                r = 10;

            joao += r;
            maria += r;
        }
        cout << solve() << endl;
    }
    return 0;
}