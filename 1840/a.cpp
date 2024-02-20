#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const double INF = 1e9 + 7;

string solve(string in) {
    string output = "";

    char now = in[0];
    for (int i = 1; i < in.length(); i++) {
        if (now == in[i]) {
            output += now;
            now = in[i+1];
            i++;
        } 
        else {
            
        }
    }
    return output;
}

int main()
{
    int runs; cin >> runs;
    while (runs--) {
        int len; cin >> len;
        string input; cin >> input;

        cout << solve(input) << endl;
    }

    return 0;
}