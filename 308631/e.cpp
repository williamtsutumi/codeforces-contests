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
    int n; cin >> n;
    map<string, int> mp;
    mp.insert(make_pair("Algebra", 0));
    mp.insert(make_pair("Aritmetica", 0));
    mp.insert(make_pair("Backtracking", 0));
    mp.insert(make_pair("Bigint", 0));
    mp.insert(make_pair("Combinatoria", 0));
    mp.insert(make_pair("Estruturas de Dados", 0));
    mp.insert(make_pair("Geometria", 0));
    mp.insert(make_pair("Ordenacao", 0));
    mp.insert(make_pair("Programacao Dinamica", 0));
    mp.insert(make_pair("SegTrees", 0));
    mp.insert(make_pair("Teoria dos Numeros", 0));
    mp.insert(make_pair("Travessia em Grafos", 0));
    for(int i=0; i<n; i++){
        string in; getline(cin, in);
        in.
        mp[in]++;
    }
    int maximo = INT_MIN;
    int minimo = INT_MAX;
    for(auto &[key, val]: mp){
        maximo = max(maximo, val);
        minimo = min(minimo, val);
    }
    int qnt = (maximo * 3) / 4;
    bool ok = true;
    for(auto &[key, val] : mp){
        if (val < qnt){
            cout << "Falta " << key << "!" << endl;
            ok = false;
        }
    }
    if (ok) cout << "Tudo em Ribas!" << endl;


    return 0;
}