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

ll parts, probs, dur;

pair<ll,ll> solve(vector<ll> &v){
    sort(v.begin(), v.end());
    ll penalty, sum;
    ll solved;
    sum = solved = penalty = 0;
    ll idx = 0;
    while (sum + v[idx] <= dur){
        sum += v[idx];
        penalty += sum;
        solved++;
        idx++;
        if (idx == v.size()) break;
    }
    return make_pair(solved, penalty);
}

int main()
{
    ll runs; cin >> runs;
    while(runs--){
        cin >> parts >> probs >> dur;
        // if (parts == 1){
        //     cout << 1 << endl; continue;
        // }
        vector<vector<ll>> vet(parts);
        for(ll i=0; i<parts; i++){
            vet[i].resize(probs);
            for (ll j=0; j<probs; j++){
                cin >> vet[i][j];
            }
        }
        vector<pair<ll,ll>> aux(parts-1);
        for(ll i=1; i<parts; i++){
            aux[i-1] = solve(vet[i]);
            // debug2(aux[i].first, aux[i].second)
        }
        sort(aux.begin(), aux.end(), [](pair<ll,ll> a, pair<ll,ll> b) -> bool {
            if (a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        });
        pair<ll,ll> pos = solve(vet[0]);
        // for (pair<ll,ll> p : aux){
        //     debug2(p.first, p.second)
        // }
        // debug2(pos.first, pos.second)
        ll output = parts;
        for (ll i=0; i<parts-1; i++){
            if (aux[i].first > pos.first) continue;
            else if (aux[i].first == pos.first){
                if (aux[i].second < pos.second) continue;
                else{
                    output = i+1;
                    break;
                }
            }
            else{
                output = i+1;
                break;
            }
        }
        cout << output << endl;
    }

    return 0;
}