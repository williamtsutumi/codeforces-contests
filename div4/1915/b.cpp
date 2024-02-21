#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
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
        string str1, str2, str3;
        cin >> str1 >> str2 >> str3;
        map<char,int> mp;
        bool ok;
        int idx;
        string str;
        for (int i=0; i<3; i++){
            if (str1[i] == '?'){
                idx = 1;
            }
            if (str2[i] == '?'){
                idx = 2;
            }
            if (str3[i] == '?'){
                idx = 3;
            }
        }
        if (idx == 1) str = str1;
        else if (idx == 2) str = str2;
        else str = str3;

        mp[str[0]]++;
        mp[str[1]]++;
        mp[str[2]]++;
        if (mp['A'] == 0) cout << 'A' << endl;
        if (mp['B'] == 0) cout << 'B' << endl;
        if (mp['C'] == 0) cout << 'C' << endl;
    }

    return 0;
}
