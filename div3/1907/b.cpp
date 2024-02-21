#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int main()
{
    FFIO;
    int r; cin >> r;
    while (r--){
        string in; cin >> in;

        string out = "";
        stack<int> ma;
        stack<int> mi;
        for (int i=0; i<in.size(); i++){
            if (in[i] != 'b' && in[i] != 'B'){
                out += in[i];

                if ('a' <= in[i] && in[i] <= 'z') mi.push(out.size()-1);
                else ma.push(out.size()-1);
            } 
            else{
                if (in[i] == 'b' && !mi.empty()){
                    int top = mi.top();
                    mi.pop();
                    out[top] = ' ';
                }
                else if (in[i] == 'B' && !ma.empty()){
                    int top = ma.top();
                    ma.pop();
                    out[top] = ' ';
                }
            }
        }
        for (int i=0; i<out.size(); i++){
            if (out[i] != ' ') cout << out[i];
        }
        cout << '\n';
    }

    return 0;
}
