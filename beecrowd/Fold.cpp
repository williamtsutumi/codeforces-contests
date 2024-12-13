#include <iostream>
#include <vector>
//https://www.beecrowd.com.br/judge/en/problems/view/1470
using namespace std;

void inverte(vector<int> &in)
{
    int its = in.size() / 2;
    for (int i = 0; i < its; i++)
    {
        int pos = in.size() - 1 - i;

        int aux = in[i];
        in[i] = in[pos];
        in[pos] = aux;
    }
}

vector<int> fold2(vector<int> in, int pos)
{
    int inSize = in.size();
    vector<int> aux;
    if (pos <= inSize / 2)
    {
        for (int i = 0; i < pos; i++)
        {
            aux.push_back(in[0]);
            in.erase(in.begin());
        }

        inverte(in);
        for (int i = 0; i < pos; i++)
            in[in.size() - pos + i] += aux[i];
    }
    else
    {
        for (int i = pos; i < inSize; i++)
        {
            aux.push_back(in[in.size() - 1]);
            in.erase(in.end() - 1);
        }

        int overlap = inSize - pos;
        for (int i = 0; i < overlap; i++)
            in[pos + i - overlap] += aux[i];
    }
    return in;
}

vector<int> fold(vector<int> &in, int pos)
{
    int inSize = in.size();
    vector<int> out;
    if (pos <= inSize / 2)
    {
        for (int i = inSize - 1; i > 2 * pos - 1; i--)
            out.push_back(in[i]);

        for (int i = pos - 1; i >= 0; i--)
            out.push_back(in[pos - 1 - i] + in[pos + i]);
    }
    else
    {
        for (int i = 0; i < pos - (inSize - pos); i++)
            out.push_back(in[i]);

        for (int i = inSize - pos - 1; i >= 0; i--)
            out.push_back(in[pos - 1 - i] + in[pos + i]);
    }
    return out;
}

bool isValid(vector<int> &in, vector<int> &out)
{
    bool valid = true;
    int inSize = in.size();

    if (inSize != out.size())
        return false;

    // ordem direta
    for (int i = 0; i < inSize; i++)
    {
        if (in[i] != out[i])
        {
            valid = false;
            break;
        }
    }
    if (valid)
        return true;

    // ordem inversa
    for (int i = 0; i < inSize; i++)
    {
        if (in[inSize - 1 - i] != out[i])
            return false;
    }
    return true;
}

string solve(vector<int> &in, vector<int> &out)
{
    int inSize = in.size();
    int outSize = out.size();
    // Caso base
    if (inSize <= outSize)
    {
        if (isValid(in, out))
            return "S";

        return "N";
    }

    vector<int> aux;
    for (int i = 1; i < inSize; i++)
    {
        aux = fold(in, i);
        if (solve(aux, out) == "S")
            return "S";
    }
    return "N";
}

int main()
{
    int inSize, outSize;
    vector<int> inputs, outputs;

    while (cin >> inSize)
    {
        inputs.clear();
        outputs.clear();
        while (inSize--)
        {
            int in;
            cin >> in;
            inputs.push_back(in);
        }
        cin >> outSize;
        while (outSize--)
        {
            int in;
            cin >> in;
            outputs.push_back(in);
        }
        cout << solve(inputs, outputs) << endl;
    }

    return 0;
}