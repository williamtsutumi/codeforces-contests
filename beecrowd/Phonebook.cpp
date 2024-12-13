#include <bits/stdc++.h>
 
using namespace std;

int charSaved = 0;

void solve(string anterior, string atual, int pos) {
    if (anterior[pos] == atual[pos]) {
        charSaved++;
        solve(anterior, atual, pos + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string numPhone;
    while(cin >> numPhone) {
        charSaved = 0;
        string anterior; cin >> anterior;
        string atual;

        for (int i = 0; i < stoi(numPhone) - 1; i++) {
            cin >> atual;
            solve(anterior, atual, 0);
            anterior = atual;
        }
        cout << charSaved << endl;
    }
 
    return 0;
}