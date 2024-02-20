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
    ll tp, bonus; cin >> tp >> bonus;
    vector<ll> tps(tp);
    vector<ll> bs(bonus);
    for (ll i=0; i<tp; i++){
        cin >> tps[i];
    }
    for(ll i=0; i<bonus; i++){
        cin >> bs[i];
    }
    if (tp==1){
        ll out = 0;
        if (bs[0] < tps[0]) out += (tps[0] - bs[0]) * 2;
        if (bs[bonus-1] > tps[0]) out += (bs[bonus-1] - tps[0]) * 2;
        cout << out << endl;
        return 0;
    }
    ll output = 0;
    if (bs[0] < tps[0]){
        output += (tps[0] - bs[0]) * 2;
    }
    
    vector<pair<int,int>> intervals;
    int idxBs = 0;
    while (bs[idxBs] < tps[0]) idxBs++;
    

    if(bs[bonus-1] > tps[tp-1]){
        output += (bs[bonus-1] - tps[tp-1]) * 2;
    }
    cout << output << endl;


    return 0;
}