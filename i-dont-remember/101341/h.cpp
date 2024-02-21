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
    int l, c; cin >> l >> c;
    vector<vector<int>> vet(l);
    for(int i=0; i<l; i++){
        vet[i].resize(c);
        for(int j=0; j<c; j++){
            cin >> vet[i][j];
        }
    }
    int maximo = INT_MIN;
    int linha = -1;
    int coluna = -1;
    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            if (vet[i][j] > maximo){
                maximo = vet[i][j];
                linha = i;
                coluna = j;
            }
        }
    }
    // cout << "********\n";
    // cout << "chute1" << endl;
    // debug(maximo)
    maximo = INT_MIN;
    pair<int,int> chute1;
    for(int i=0; i<l; i++){
        if (i != linha){
            for(int j=0; j<c; j++){
                if (vet[i][j] > maximo){
                    maximo = vet[i][j];
                    chute1 = make_pair(linha, j);
                }
            }
        }
    }
    // cout << chute1.first+1 << endl;
    // cout << chute1.second+1 << endl;
    // cout << "********\n";
    // cout << "chute2" << endl;
    maximo = INT_MIN;
    pair<int,int> chute2;
    for(int i=0; i<c; i++){
        if (i != coluna){
            for(int j=0; j<l; j++){
                if (vet[j][i] > maximo){
                    maximo = vet[j][i];
                    chute2 = make_pair(j, coluna);
                }
            }
        }
    }
    // cout << chute2.first+1 << endl;
    // cout << chute2.second+1 << endl;
    int max1 = INT_MIN;
    for(int i=0; i<c; i++){
        if (i != chute1.second){
            for(int j=0; j<l; j++){
                if (j != chute1.first){
                    if (vet[j][i] > max1){
                        max1 = vet[j][i];
                    }
                }
            }
        }
    }
    int max2 = INT_MIN;
    for(int i=0; i<c; i++){
        if (i != chute2.second){
            for(int j=0; j<l; j++){
                if (j != chute2.first){
                    if (vet[j][i] > max2){
                        max2 = vet[j][i];
                    }
                }
            }
        }
    }
    if (max1 < max2)
        cout << chute1.first+1 << " " << chute1.second+1 << endl;
    else
        cout << chute2.first+1 << " " << chute2.second+1 << endl;
    

    return 0;
}