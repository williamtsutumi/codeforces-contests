#include <iostream>
#include <vector>
#include <algorithm>
//https://www.beecrowd.com.br/judge/en/problems/view/1252
using namespace std;

bool myComparator(pair<int, int> p1, pair<int, int> p2)
{
    int sec1 = p1.second;
    int first1 = p1.first;
    int sec2 = p2.second;
    int first2 = p2.first;
    if (sec1 == sec2)
    {
        int ehPar1 = first1 % 2;
        int ehPar2 = first2 % 2;
        // um par um impar
        if (ehPar1 == 0 && ehPar2)
            return false;
        else if (ehPar1 && ehPar2 == 0)
            return true;
        // dois impar
        else if (ehPar1 && ehPar1)
            return first1 > first2;
        // dois par
        else if (ehPar1 == 0 && ehPar2 == 0)
            return first1 < first2;
    }
    return p1.second < p2.second;
}

int main()
{
    vector<pair<int, int>> vet;
    int qntNums;
    int mod;
    while (cin >> qntNums >> mod)
    {
        cout << qntNums << " " << mod << endl;
        vet.clear();
        
        while (qntNums--)
        {
            int num; cin >> num;
            pair<int, int> par(num, num % mod);
            vet.push_back(par);
        }
        sort(vet.begin(), vet.end(), myComparator);
        
        for (pair<int, int> p : vet)
        {
            cout << p.first << endl;
        }
    }

    return 0;
}