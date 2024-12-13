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
    int p;
    while (cin >> p){
        vector<int> up;
        vector<int> down;
        for (int i=0; i<p; i++){
            int time, side; cin >> time >> side;
            if (side == 0){
                up.push_back(time);
            }
            else{
                down.push_back(time);
            }
        }
        sort(up.begin(), up.end());
        sort(down.begin(), down.end());

        int auxU, auxD;
        auxU = auxD = 0;
        int time = 0;
        debug2(up.size(), down.size())
        debug2(auxU, auxD)
        while (auxD < down.size() || auxU < up.size()) {
            // debug(time)
            bool a;
            if (auxD == down.size()) a = true;
            else if (auxU == up.size()) a = false;
            else a = up[auxU] < down[auxD];

            if (a){
                time = up[auxU]+10;
                auxU++;
                while (auxU < up.size() && time > up[auxU+1]){
                    time = up[auxU+1]+10;
                    auxU++;
                }
            }
            else {
                time = up[auxD]+10;
                auxD++;
                while (auxU < up.size() && time > up[auxD+1]){
                    time = up[auxD+1]+10;
                    auxD++;
                }
            }
        }
        cout << time+10 << endl;
    }

    return 0;
}