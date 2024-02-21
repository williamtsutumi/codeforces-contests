#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debugbr.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long double ld;
typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int sums[100][100];
vector<string> in;
int n;

void sumall(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(in[i][j] == '1') sums[i][j]++;
        }
    }
}

void rot(){
    vector<string> aux(n, "");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //aux[j][i] = in[n-1-i][j];
            aux[j].push_back(in[n-1-i][j]);
        }
    }
    in = aux;
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        cin >> n;
        in.resize(n);
        memset(sums, 0, sizeof(sums));
        for(int i=0; i<n; i++) cin >> in[i];

        sumall();
        rot();
        sumall();
        rot();
        sumall();
        rot();
        sumall();

        int its1 = ceil(n/2.0);
        int its2 = floor(n/2.0);
        ll out = 0;
        for(int i=0; i<its1; i++){
            for(int j=0; j<its2; j++){
                out += min(sums[i][j], 4-sums[i][j]);
            }
        }
        cout << out << '\n';
    }

    return 0;
}
