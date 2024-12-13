#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string notas[12] = {
        "do",
        "do#",
        "re",
        "re#",
        "mi",
        "fa",
        "fa#",
        "sol",
        "sol#",
        "la",
        "la#",
        "si",
    };
    int numInputs;
    cin >> numInputs;
    int in;
    vector<string> output = {};
    while (cin >> in)
    {
        output.push_back(notas[in % 12]);
    }

    for (string nota : output)
    {
        cout << nota << " ";
    }

    return 0;
}