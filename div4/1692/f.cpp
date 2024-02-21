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

        for(int i=0; i<n; i++) in[i] %= 10;

        vector<int> cnt(10);
        for(int i=0; i<n; i++) cnt[in[i]]++;

        bool ok = false;
        for(int i=0; i<10; i++){
            if (cnt[i] == 0) continue;
            for(int j=0; j<10; j++){
                if (cnt[j] == 0) continue;
                for(int k=0; k<10; k++){
                    if(cnt[k] == 0) continue;

                    if (i == j && cnt[i] < 2) continue;
                    if (j == k && cnt[j] < 2) continue;
                    if (i == k && cnt[i] < 2) continue;
                    if (i == j && i == k && cnt[i] < 3) continue;

                    if ((i+j+k) % 10 == 3){
                        ok = true;
                    }
                }
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
