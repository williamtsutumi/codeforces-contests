#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
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
        int lins, cols; cin >> lins >> cols;
        vector<string> in(lins);
        for(int i=0; i<lins; i++) cin >> in[i];

        vector<pair<int,int>> changes;
        int idx = lins-1;
        for(int j=0; j<cols; j++){
            idx = lins-1;
            for(int i=lins-1; i>=0; i--){
                if (in[i][j] == 'o'){
                    idx = i-1;
                }
                else if (in[i][j] == '.'){
                    continue;
                }
                else if (in[i][j] == '*'){
                    changes.push_back({idx, j});
                    idx--;
                }
            }
        }
        for(int i=0; i<lins; i++){
            for(int j=0; j<cols; j++){
                if (in[i][j] == '*') in[i][j] = '.';
            }
        }
        for(int i=0; i<changes.size(); i++){
            in[changes[i].first][changes[i].second] = '*';
        }
        for(int i=0; i<lins; i++){
            cout << in[i] << '\n';
        }
        cout << '\n';
    }

    return 0;
}
