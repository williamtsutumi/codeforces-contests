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
        string in; cin >> in;
        for(int i=0; i<n; i++){
            int num;
            if (i+3 < n && in[i+2] == '0' && in[i+3] == '0'){
                num = (in[i]-'0');
            }
            else if (i+2 < n && in[i+2] == '0'){
                num = (in[i]-'0')*10 + (in[i+1]-'0');
                i += 2;
            }
            else{
                num = (in[i]-'0');
            }
            cout << (char)(num+'a'-1);
        }
        cout << '\n';
    }

    return 0;
}
