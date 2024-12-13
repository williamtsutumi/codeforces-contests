#include <iostream>

using namespace std;


int main()
{
    int n; cin >> n;
    int vet[n];
    for (int i = 0; i < n - 1; i++)
    {
        int num; cin >> num;
        vet[num - 1] = 1;
    }

    int output = 0;
    while (vet[output] == 1)
        output++;
    cout << output + 1 << endl;


    return 0;
}