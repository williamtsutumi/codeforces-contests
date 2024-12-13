#include <iostream>
#include <string>
#include <stack>

using namespace std;

int priority(string op)
{
    int carac = op[0];
    if (carac == '+' || carac == '-')
        return 1;
    else if (carac == '*' || carac == '/')
        return 2;
    else if (carac == '^')
        return 3;

    return -1;
}

string solve(string in)
{
    string out;
    string operacoes = "+-*/^";
    stack<string> pilha;
    pilha.push("#");

    int len = in.length();
    for (int i = 0; i < len; i++)
    {
        string carac;
        carac.push_back(in.at(i));
        // se é operação
        if (operacoes.find(carac) != string::npos)
        {
            if (priority(carac) > priority(pilha.top()))
                pilha.push(carac);
            else
            {
                while (pilha.top() != "#" && priority(carac) <= priority(pilha.top()))
                {
                    out += pilha.top();
                    pilha.pop();
                }
                pilha.push(carac);
            }
        }
        else if (carac == "(")
            pilha.push(carac);

        else if (carac == ")")
        {
            while (pilha.top() != "#" && pilha.top() != "(")
            {
                out += pilha.top();
                pilha.pop();
            }
            // retira (
            pilha.pop();
        }
        // se é letra ou número
        else
            out += carac;
    }
    while (pilha.top() != "#")
    {
        out += pilha.top();
        pilha.pop();
    }
    return out;
}

int main()
{
    int numTests;
    cin >> numTests;
    while (numTests--)
    {
        string in;
        cin >> in;
        cout << solve(in) << endl;
    }

    return 0;
}