#include <iostream>
#include <set>
//https://www.beecrowd.com.br/judge/en/problems/view/1215
using namespace std;

int main()
{
    set<string> s;

    string word;
    while (cin >> word)
    {
        word += ".";
        string toAdd = "";
        for (int i = 0; i < word.length(); i++)
        {
            char carac = tolower(word.at(i));
            if ('a' <= carac && carac <= 'z')
            {
                toAdd += carac;
            }
            else if (toAdd != "")
            {
                s.insert(toAdd);
                toAdd = "";
            }
        }
    }
    for (string w : s)
    {

        cout << w << endl;
    }

    return 0;
}