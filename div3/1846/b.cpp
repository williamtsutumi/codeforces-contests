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

vector<vector<char>> v;

bool h(int idx){
    return v[idx][0] != '.' && (v[idx][0] == v[idx][1] && v[idx][1] == v[idx][2]);
}

bool vt(int idx){
    return v[0][idx] != '.' && (v[0][idx] == v[1][idx] && v[1][idx] == v[2][idx]);
}

bool d(){
    return v[1][1] != '.' && ((v[0][0] == v[1][1] && v[2][2] == v[1][1]) || (v[0][2] == v[1][1] && v[2][0] == v[1][1]));
}

int main()
{
    int runs; cin >> runs;
    while(runs--){
        v.clear();
        v.resize(3);
        for (int i=0; i <3; i++){
            for (int j=0; j<3; j++){
                char c; cin >> c;
                v[i].push_back(c);
            }
        }
        // debug(h(0))
        // debug(h(1))
        // debug(h(2))
        // debug(vt(0))
        // debug(vt(1))
        // debug(vt(2))
        // debug(d())
        if (h(0)) cout << v[0][0] << endl;
        else if (h(1)) cout << v[1][0] << endl;
        else if (h(2)) cout << v[2][0] << endl;
        else if (vt(0)) cout << v[0][0] << endl;
        else if (vt(1)) cout << v[0][1] << endl;
        else if (vt(2)) cout << v[0][2] << endl;
        else if (d()) cout << v[1][1] << endl;
        else cout << "DRAW" << endl;
        // cout << "---------------------" << endl;
    }

    return 0;
}