#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double
#define X real()
#define Y imag()

typedef long long C;
typedef complex<C> P;
typedef long long ll;
const double INF = 1e9 + 7;

int main()
{
    string a,b,c; cin >> a >> b >> c;
    // debug(a)
    // debug(b)
    // debug(c)
    string output = "";
    int count = 0;
    int i_count = 0;
    for (int i=0; i<a.length(); i++){
        if (a[i] != b[i] && a[i] != c[i] && b[i] != c[i]){
            i_count++;
            if (i_count == 1){
                cout << "Impossible" << endl;
                return 0;
            }
        }
        if (a[i] != b[i] || a[i] != c[i] || b[i] != c[i]) count++;
    }
    if (i_count > 0 && count > 0){
        cout << "Impossible" << endl;
        return 0;
    }
    else if (count == 0 || i_count==1){
        cout << "Ambiguous" << endl;
        return 0;
    }
    else if (count == 2){
        cout << "Ambiguous" << endl;
        return 0;
    }
    else if (count == 3){
        for (int i=0; i<a.length(); i++){
            if (a[i] == b[i]) output += a[i];
            else if (a[i] == c[i]) output += a[i];
            else if (b[i] == c[i])  output += b[i];
        }
        cout << output << endl;
        return 0;
    }

    return 0;
}