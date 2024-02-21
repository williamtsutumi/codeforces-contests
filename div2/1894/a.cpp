#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
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

int solve(string in, int x){
    int a = 0, b = 0;
    int ca = 0, cb = 0;
    for (int i=0; i<in.size(); i++){
        if (in[i] == 'A'){
            ca++;
            if (ca == x){
                a++;
                ca = 0;
                cb = 0;
            }
        }
        else if (in[i] == 'B'){
            cb++;
            if (cb == x){
                b++;
                ca = 0;
                cb = 0;
            }
        }
    }
    if (a == b) return -1;
    else if (a > b) return 1;
    else return 0;
}

int main()
{
    int runs; cin >> runs;
    while(runs--){
        int n; cin >> n;
        string in; cin >> in;
        
        cout << in[in.size() - 1] << endl;
        continue;

        int last = solve(in, 1);
        bool ok = true;
        for (int i=2; i<=in.size(); i++){
                bool aux = solve(in, i);
                if (aux == -1) continue;
                if (aux != last){
                    ok = false;
                    break;
                }
                last = aux;
        }
        //if (!ok) cout << "?" << endl;
        //else if (last) cout << "A" << endl;
        //else cout << "B" << endl;
    }

    return 0;
}
