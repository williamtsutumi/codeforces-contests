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
        string in; cin >> in;
        map<int, int> mp;
        for(int i=0; i<in.size(); i++){
            mp[in[i]]++;
        }
        if (mp['A'] > mp['B']) cout << 'A' << '\n';
        else cout << 'B' << '\n';
    }

    return 0;
}
