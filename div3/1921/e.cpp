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
    while(r--){
        int lines, cols; cin >> lines >> cols;
        pair<int,int> a, b;
        cin >> a.first >> a.second >> b.first >> b.second;

        if (a.first >= b.first){
            cout << "Draw\n";
            continue;
        }

        int dlin = b.first - a.first;
        int t = dlin / 2;

        if (dlin % 2 == 0){
            if (a.second > b.second){
                if (cols > b.second + t){
                    cout << "Draw\n";
                    continue;
                }
                else{
                    cout << "Bob\n";
                    continue;
                }
            }
            else if (a.second < b.second){
                if (1 < b.second - t){
                    cout << "Draw\n";
                    continue;
                }
                else{
                    cout << "Bob\n";
                    continue;
                }
            }
            else{
                cout << "Bob\n";
                continue;
            }
        }
        else{
            if (a.second > b.second){
                if (1 < a.second - t){
                    cout << "Draw\n";
                    continue;
                }
                else{
                    cout << "Alice\n";
                    continue;
                }
            }
            else if (a.second < b.second){
                if (cols > a.second + t){
                    cout << "Draw\n";
                    continue;
                }
                else{
                    cout << "Alice\n";
                    continue;
                }
            }
            else{
                cout << "Alice\n";
                continue;
            }
        }
    }

    return 0;
}
