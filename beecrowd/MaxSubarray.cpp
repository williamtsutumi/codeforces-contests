#include <bits/stdc++.h>

using namespace std;
// n^2
// int solve(vector<int> &vet, int subarr_size)
// {
//     if (subarr_size == 0)
//         return INT_MIN;

//     int size = vet.size();
//     int its = size - subarr_size;
//     int output = INT_MIN;
//     for (int i = 0; i < its; i++)
//     {
//         int sum = vet[i + subarr_size] - vet[i];
//         output = max(output, sum);
//     }
//     return max(output, solve(vet, subarr_size - 1));
// }
int solve(vector<int> &vet)
{
    auto esq = vet.begin();
    auto dir = vet.begin() + 1;

    int output = *esq;
    int sum = *esq;

    while (dir != vet.end())
    {
        if (*dir > sum + *dir)
        {
            esq = dir;
            sum = *dir;
        }
        else
        {
            dir++;
            sum += *dir;
        }
        output = max(output, sum);
    }
    return output;
}

int main()
{
    int numInputs;
    cin >> numInputs;
    vector<int> vet;
    for (int i = 0; i < numInputs; i++)
    {
        int in;
        cin >> in;
        // int prev = vet[i];
        vet.push_back(in);
    }
    cout << solve(vet) << endl;

    return 0;
}