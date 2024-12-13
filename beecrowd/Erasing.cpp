#include <iostream>
#include <string>

using namespace std;

string maiorDigito(string str)
{
    string maior = "0";
    for (int i = 0; i < str.length(); i++)
    {
        string digito = str.substr(i, 1);
        if (digito > maior)
            maior = digito;
    }
    return maior;
}

string MaiorNum(string num, int apagar)
{
    if (apagar == 0)
        return num;
    if (num.length() == apagar)
        return "";

    string maior = maiorDigito(num.substr(0, apagar + 1));
    int idxMaiorDigito = num.find(maior);

    return maior + MaiorNum(
                       num.substr(idxMaiorDigito + 1, num.length() - idxMaiorDigito),
                       apagar - idxMaiorDigito);
}

int main()
{
    int digitos;
    int apagar;
    string num;

    while (cin >> digitos >> apagar)
    {
        if (digitos == 0 && apagar == 0)
            break;
        cin >> num;
        cout << MaiorNum(num, apagar) << endl;
    }

    return 0;
}