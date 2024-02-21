#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int main()
{
    int runs; cin >> runs;
    vector<string> inputs;
    int lin, col;
    while (runs--){
        cin >> lin >> col;
        inputs.resize(lin);
        for(int i=0; i<lin; i++){
            cin >> inputs[i];
        }
        bool ok = false;
        char curr = 'v';
        for(int j=0; j<col; j++){
            for(int i=0; i<lin; i++){
                if (inputs[i][j] == curr){
                    if (curr == 'v'){
                        curr = 'i';
                        break;
                    }
                    if (curr == 'i'){
                        curr = 'k';
                        break;
                    }
                    if (curr == 'k'){
                        curr = 'a';
                        break;
                    }
                    if (curr == 'a'){
                        ok = true;
                        break;
                    }
                }
            }
            if (ok) break;
        }
        if (ok)cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}