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
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        vector<string> in(n);
        for(int i=0; i<n; i++) cin >> in[i];

        pair<int,int> f = {-1, -1};
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (in[i][j] == '1'){
                    f = {i,j};
                    break;
                }
            }
            if (f != make_pair(-1, -1)) break;
        }
        if (in[f.first+1][f.second] == '0' || in[f.first][f.second+1] == '0'){
            //find triangle
            cout << "TRIANGLE\n";
        }
        else{
            // find square
            cout << "SQUARE\n";
            /*
            int cnt = 1;
            auto start = f;
            while(f.first == '1'){
                f.first++;
                cnt++;
            }
            bool ok = true;
            for(int i=start.first; i<start.first+cnt; i++){
                for(int j=start.second; j<start.second+cnt; j++){
                    if (in[i][j] == '0'){
                        ok = false;
                        break;
                    }
                }
            }
            */

        }
    }

    return 0;
}
