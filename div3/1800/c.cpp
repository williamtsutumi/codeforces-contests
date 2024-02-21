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
        int n; cin >> n;
        vector<int> in(n);
        for(int i=0; i<n; i++) cin >> in[i];

        int start = 0;
        while(start < n && in[start] == 0) start++;

        vector<int> aux;
        ll out = 0;
        bool found = false;
        for(int i=start; i<=n; i++){
            if (found && (i == n || in[i] > 0)){
                found = false;
                int idx = 0;
                sort(aux.begin(), aux.end());
                while(aux[idx] == 0){
                    out += aux[aux.size()-1-idx];
                    idx++;
                }
                aux.erase(next(aux.begin(), aux.size()-1-idx), aux.end());
                if (idx == 0) aux.erase(aux.begin());
                else aux.erase(aux.begin(), next(aux.begin(), idx-1));
                debug(aux);

            }
            if (i == n) break;

            if (in[i] == 0) found = true;
            aux.push_back(in[i]);
        }
        cout << out << '\n';
    }

    return 0;
}
