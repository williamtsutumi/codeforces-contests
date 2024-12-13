#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int absSumAdjacent(deque<int> ans)
{
    int size = ans.size();
    int out = 0;
    for (int i = 0; i < size - 1; i++)
    {
        out += abs(ans[i] - ans[i + 1]);
    }
    return out;
}

int solve(deque<int> &in)
{
    int size = in.size();
    sort(in.begin(), in.end());

    deque<int> ans = {in[0]};

    int toCheck = (size / 2);
    if (size % 2 == 0)
        toCheck--;

    for (int i = 0; i < toCheck; i++)
    {
        if (i % 2 == 0)
        {
            int maior1 = in[size - 1 - i];
            int maior2 = in[size - 2 - i];
            ans.push_front(maior1);
            ans.push_back(maior2);
        }
        else
        {
            int menor1 = in[i];
            int menor2 = in[i + 1];
            ans.push_front(menor1);
            ans.push_back(menor2);
        }
    }
    if (size % 2 == 0)
    {
        int naoColocado = in[size / 2];
        if (find(ans.begin(), ans.end(), naoColocado) != ans.end())
            naoColocado = in[size / 2 - 1];

        if (abs(naoColocado - ans[0]) > abs(naoColocado - ans[ans.size() - 1]))
            ans.push_front(naoColocado);
        else
            ans.push_back(naoColocado);
    }
    else
    {
        int ansSize = ans.size();
        int ultimo = ans[ansSize - 1];
        if (abs(ultimo - ans[ansSize - 2]) < abs(ultimo - ans[0]))
        {
            ans.erase(ans.end() - 1);
            ans.push_front(ultimo);
        }
    }
    // for (int v : ans)
    //     cout << v << endl;
    return absSumAdjacent(ans);
}

int main()
{
    int numTests;
    cin >> numTests;
    for (int i = 1; i <= numTests; i++)
    {
        int numInput;
        cin >> numInput;

        deque<int> in;
        while (numInput--)
        {
            int input;
            cin >> input;
            in.push_back(input);
        }
        cout << "Case " << i << ": " << solve(in) << endl;
    }

    return 0;
}