#include <iostream>
#include <unordered_map>
#include <limits.h>
//https://www.beecrowd.com.br/judge/en/problems/view/1251
using namespace std;

void printOrdem(unordered_map<int, int> mp)
{
    while (!mp.empty())
    {
        pair<int, int> nextToPrint(INT_MAX, INT_MAX);
        unordered_map<int, int>::iterator idx = mp.begin();
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if ((*it).second < nextToPrint.second)
            {
                idx = it;
                nextToPrint = make_pair((*it).first, (*it).second);
            }
            else if ((*it).second == nextToPrint.second)
            {
                if ((*it).first > nextToPrint.first)
                {
                    idx = it;
                    nextToPrint = make_pair((*it).first, (*it).second);
                }
            }
        }
        cout << nextToPrint.first << " " << nextToPrint.second << endl;
        
        mp.erase(idx);
    }
}

int main()
{
    string in;
    bool naoPrimeiro = false;
    while (cin >> in)
    {
        if (naoPrimeiro)
        {
            cout << endl;
        }
        naoPrimeiro = true;
        unordered_map<int, int> mp;
        for (int i = 0; i < in.length(); i++)
        {
            char c = in.at(i);
            mp[c]++;
        }
        printOrdem(mp);
    }

    return 0;
}