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

int main()
{
    FFIO;
    int n; cin >> n;
    string str = "codeforces";
    while (n--){
        string in; cin >> in;
        int out = 0;
        for (int i=0; i<in.size(); i++){
            if (in[i] != str[i]) out++;
        }
        cout << out << '\n';
    }

    return 0;
}

