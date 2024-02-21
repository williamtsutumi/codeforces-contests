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
    int n; cin >> n;
    pair<int,int> p;
    vector<pair<int,int>> vet(n);
    for (int i=0; i<n; i++){
        int a,b; cin >> a >> b;
        p = make_pair(a, b);
        vet[i] = p;
    }
    sort(vet.begin(), vet.end(), [](pair<int,int> a, pair<int,int> b) -> bool {
        return a.second < b.second;
    });
    // for (int i=0; i<n; i++){
    //     debug(vet[i].first)
    //     debug(vet[i].second)
    // }
    vector<int> output;
    output.push_back(vet[0].second);
    int idx = 0;
    for (int i=0; i<n; i++){
        // debug(output[idx])
        // debug(vet[i].first)
        if (vet[i].first <= output[idx]){
            continue;
        }

        output.push_back(vet[i].second);
        idx++;
    }
    cout << output.size() << endl;
    for (int i=0; i<output.size(); i++){
        if (i == output.size() -1)
            cout << output[i];
        else
            cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}