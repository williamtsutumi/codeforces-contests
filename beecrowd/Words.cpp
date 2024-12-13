#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<pair<string, vector<string>>, int> dp;

int startWith(string palavra, vector<string> &toComplete, vector<string> &otherSet)
{
    // pair<string, vector<string>> par(palavra, toComplete);
    // if (dp[par] == -1)
    //     return -1;

    if (palavra == "")
        return 1;

    // dp[par] = -1;
    for (string p : toComplete)
    {
        string aux;
        if (p.size() > palavra.size())
        {
            aux = p.substr(0, palavra.size());
            if (aux == palavra)
            {
                if(startWith(p.substr(palavra.size(), p.size() - palavra.size()), otherSet, toComplete) == 1)
                {
                    return 1;
                    // dp[par] = 1;
                }
            }
        }
        else
        {
            aux = palavra.substr(0, p.size());
            if (aux == p)
            {
                if(startWith(palavra.substr(p.size(), palavra.size() - p.size()), toComplete, otherSet) == 1)
                {
                    return 1;
                    // dp[par] = 1;
                }
            }
        }
    }
    return -1;
    // return dp[par];
}

string solve(vector<string> setUm, vector<string> setDois)
{
    for (int i = 0; i < setUm.size(); i++)
    {
        dp.clear();
        if (startWith(setUm.at(i), setDois, setUm) == 1)
            return "S";
    }
    return "N";
}

int main()
{
    int numSetUm, numSetDois;
    while (cin >> numSetUm >> numSetDois)
    {
        vector<string> setUm, setDois;
        for (int i = 1; i <= numSetUm; i++)
        {
            string in; cin >> in;
            setUm.push_back(in);
        }
        for (int i = 1; i <= numSetDois; i++)
        {
            string in; cin >> in;
            setDois.push_back(in);
        }
        cout << solve(setUm, setDois) << endl;
    }

    return 0;
}