#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    vector<int> output;
    int size = arr.size();
    int lastIdx = size - 1;
    int dx = size / 2;
    int toCheck = dx;
    // Encontrando o índice do elemento mais próximo de x
    while (dx > 0)
    {
        if (toCheck >= lastIdx)
        {
            if (abs(arr[toCheck - 1] - x) > abs(arr[toCheck] - x))
                toCheck = lastIdx;
            else
                toCheck = lastIdx - 1;
            break;
        }
        else if (toCheck <= 0)
        {
            if (abs(arr[toCheck] - x) > abs(arr[toCheck + 1] - x))
                toCheck = 1;
            break;
        }
        dx /= 2;
        if (arr[toCheck] == x)
            break;
        else if (abs(arr[toCheck] - x) > abs(arr[toCheck + 1] - x))
            toCheck += dx + 1;
        else
            toCheck -= dx + 1;
    }
    // Colocando os elementos que devem estar no output
    output.push_back(arr[toCheck]);
    int esq = toCheck - 1;
    int dir = toCheck + 1;
    while (output.size() < k)
    {
        if (esq < 0)
        {
            output.push_back(arr[dir]);
            dir++;
            continue;
        }
        else if (dir > lastIdx)
        {
            output.push_back(arr[esq]);
            esq--;
            continue;
        }
        if (abs(arr[esq] - x) <= abs(arr[dir] - x))
        {
            output.push_back(arr[esq]);
            esq--;
        }
        else
        {
            output.push_back(arr[dir]);
            dir++;
        }
    }
    sort(output.begin(), output.end());
    return output;
}

int main()
{
    vector<int> arr = {1,1,1,10,10,10};
    int k = 1;
    int x = 2;

    vector<int> out;
    out = findClosestElements(arr, k, x);
    for (int i = 0; i < out.size(); i++)
        cout << out[i] << endl;

    return 0;
}