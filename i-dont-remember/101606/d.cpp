#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const double INF = 1e9 + 7;

int main()
{
    string in; cin >> in;
    debug(in)
    map<char, vector<int>> mp;
    for(int i=0; i<in.size(); i++){
        mp[in[i]].push_back(i);
    }
    string sorted = in;
    sort(sorted.begin(), sorted.end());
    debug(sorted)
    bool ok = false;
    char aux = ' ';
    int idx = 0;
    while(!ok){
        ok = true;
        for(int i=0; i<in.size(); i++){
            debug(i)
            if (!ok && sorted[i] != aux){
                idx = 0;
                break;
            }

            if(sorted[i] != in[i]){
                ok = false;
                aux = sorted[i];

                if(i == mp[sorted[i]][idx]){
                    idx++;
                    continue;
                }
                if(idx == mp[sorted[i]].size()){
                    idx = 0;
                    break;
                }
                char c = sorted[i];
                sorted[i] = sorted[mp[sorted[i]][idx]];
                sorted[mp[sorted[i]][idx]] = c;
                cout << i << ' ' << mp[sorted[i]][idx] << endl;

                idx++;
            }
        }
    }



    return 0;
}