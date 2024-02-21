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
    int p,m,g; cin >> p >> m >> g;
    int cap, n; cin >> cap >> n;
    vector<int> vet(n, cap);
    int a,b,c;
    int out = 0;
    a = b = c = 0;
    for(int i=0; i<n; i++){
        char in; cin >> in;
        // cout << "***************\n";
        // debug(in)
        if (in == 'F'){
            // debug(a)
            // debug(b)
            // debug(c)
            vet[a] -= p;
            out = max(out, a);
            // a++;
            if (a == b){
                while(vet[b] < m) b++;
            }
            if (a == c){
                while(vet[c] < g) c++;
            }
            while(vet[a] < p) a++;
            // debug(a)
            // debug(b)
            // debug(c)
        }
        else if (in == 'A'){
            // debug(a)
            // debug(b)
            // debug(c)
            vet[b] -= m;
            out = max(out, b);
            if (a == b){
                while(vet[a] < p) a++;
            }
            if (b == c){
                while(vet[c] < g) c++;
            }
            // b++;
            while(vet[b] < m) b++;
            // debug(a)
            // debug(b)
            // debug(c)
        }
        else if (in == 'R'){
            // debug(a)
            // debug(b)
            // debug(c)
            vet[c] -= g;
            out = max(out, c);
            if (c == b){
                while(vet[b] < m) b++;
            }
            if (c == a){
                while(vet[a] < p) a++;
            }
            // c++;
            while(vet[c] < g) c++;
            // debug(a)
            // debug(b)
            // debug(c)
        }
    }
    cout << out+1 << endl;

    return 0;
}