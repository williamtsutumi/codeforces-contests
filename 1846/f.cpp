#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) std::cout << #x << " = " << x << std::endl;
#define debug2(x, y) std::cout << #x << " = " << x << ", " << #y << " = " << y << std::endl;
#define ld long double

typedef vector<int> vi;
typedef pair<int, int> pii;
// const double INF = 1e9 + 7;

__int128 val(__int128 b, __int128 pot, __int128 n){
    __int128 out = 0;
    __int128 aux = 1;
    for (int i=0; i<pot; i++){
        out += aux;
        if (out > n) return 1;
        aux *= b;
    }
    if (out == n) return 0;
    else return -1;
}

int main()
{
    int runs; cin >> runs;
    while(runs--){
        string output = "NO";
        long long n; cin >> n;
        if (n < 7){
            cout << "NO" << endl;
            continue;
        }
        for(ld i=3; i<=64; i++){
            __int128 minimo = 2;
            __int128 maximo = n;
            while(minimo <= maximo){
                __int128 meio = (minimo + maximo) / 2;
                __int128 value = val(meio, i, n);
                if (value == 0){
                    output = "YES";
                    break;
                }

                if(value == -1){
                    minimo = meio + 1;
                }
                else{
                    maximo = meio - 1;
                }
            }
            if (output == "YES") break;
        }
        cout << output << endl;
    }

    return 0;
}