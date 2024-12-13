#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool retiraResto(map<int, int> &mp, int resto)
{
    if (resto == 1)
    {
        // tenta retirar um de resto
        for (int i = 1; i <= 7; i += 3)
        {
            if (mp[i] >= 1)
            {
                mp[i]--;
                return true;
            }
        }
        // tenta retirar dois de resto (tem que retirar mais dois de resto)
        // e aplica recursao
        for (int i = 2; i <= 8; i += 3)
        {
            if (mp[i] >= 1)
            {
                mp[i]--;
                return retiraResto(mp, 2);
            }
        }
    }
    else if (resto == 2)
    {
        // tenta retirar o resto dois
        for (int i = 2; i <= 8; i += 3)
        {
            if (mp[i] >= 1)
            {
                mp[i]--;
                return true;
            }
        }
        // tenta retirar um de resto e aplica recursao
        for (int i = 1; i <= 7; i += 3)
        {
            if (mp[i] >= 1)
            {
                mp[i]--;
                return retiraResto(mp, 1);
            }
        }
    }
    return false;
}

string solve(vector<int> digits)
{
    map<int, int> mp;
    int sum = 0;
    for (int d : digits)
    {
        mp[d]++;
        sum += d;
    }
    if (mp[0] == 0)
        return "-1";

    if (sum % 3 == 1)
    {
        if (!retiraResto(mp, 1))
            return "-1";
    }
    else if (sum % 3 == 2)
    {
        if (!retiraResto(mp, 2))
            return "-1";
    }

    string out;
    for (int i = 9; i >= 0; i--)
    {
        while (mp[i]--)
            out += to_string(i);
    }
    if (out[0] == '0')
        return "0";
    if (out.length() >= 4)
        return out;

    int output = stoi(out);
    if (output < 30)
        return "-1";

    return out;
}

int main(int argc, char *argv[])
{
    int numDigits;
    cin >> numDigits;
    vector<int> digits;
    while (numDigits--)
    {
        int digit;
        cin >> digit;
        digits.push_back(digit);
    }
    cout << solve(digits) << endl;

    return 0;
}