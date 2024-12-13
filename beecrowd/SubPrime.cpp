#include <iostream>

using namespace std;

int main()
{
    string output = "";

    while (true) {
        int numBanks;
        cin >> numBanks;
        int numLines;
        cin >> numLines;

        if (numLines == 0 && numBanks == 0) break;

        int banksMoney[numBanks];
        for (int i = 0; i < numBanks; i++)
        {
            cin >> banksMoney[i];
        }

        for (int i = 0; i < numLines; i++)
        {
            int debtor;
            cin >> debtor;

            int creditor;
            cin >> creditor;
            
            int amount;
            cin >> amount;

            banksMoney[debtor - 1] -= amount;
            banksMoney[creditor - 1] += amount;
        }

        int menor = banksMoney[0];
        for (int i = 0; i < numBanks; i++)
        {
            if (banksMoney[i] < menor)
            {
                menor = banksMoney[i];
            }
        }

        if (menor < 0)
            output += "N";
        else
            output += "S";
    }

    for (int i = 0; i < output.length(); i++) {
        cout << output.substr(i, 1) << endl;
    }

    return 0;
}