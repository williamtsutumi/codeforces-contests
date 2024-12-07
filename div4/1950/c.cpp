#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long double ld;
typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int hour(string s){ return stoi(s.substr(0, 2)); }
int minu(string s) { return stoi(s.substr(3, 2)); }

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        string in; cin >> in;
        string ho = in.substr(0,2);
        string mi = in.substr(3,2);
        int h = hour(in);
        int m = minu(in);
        string hor;
        if (h != 0 && h <= 11 && m <= 59){
            cout << ho << ':' << mi << " AM\n";
            continue;
        } 
        else if (h == 0){
            cout << 12 << ':' << mi << " AM\n";
            continue;
        }
        else {
            if (h > 12) h = h-12;
            if (h <= 9) hor = "0" + to_string(h);
            else hor = to_string(h);
            cout << hor << ':' << mi << " PM\n";
        }
    }

    return 0;
}
