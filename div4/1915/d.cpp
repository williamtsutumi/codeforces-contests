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

bool isconsonant(char c){
    return c == 'b' || c == 'c' || c == 'd';
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        string in; cin >> in;

        vector<int> indexes;
        for (int i=0; i<n; i++){
            if (in[i] == 'a' || in[i] == 'e'){
                if ((i+1 < n && isconsonant(in[i+1])) && i+2 < n && isconsonant(in[i+2])) indexes.push_back(i+2);
                else indexes.push_back(i+1);
            }
        }

        for (int i=indexes.size()-1; i>=0; i--){
            if (indexes[i] >= n-1) continue;
            in.insert(indexes[i], ".");
        }
        cout << in << endl;
    }

    return 0;
}
