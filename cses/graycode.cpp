#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../debug.h"
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
    int mx = 1 << n;

    for (int i=0; i<mx; i++){
        int num = i;
        int cnt = 0;
        stack<int> stk;
        while (num > 0){
            stk.push(num%2);
            num/=2;
            cnt++;
        }

        while (cnt < n){
            cout << 0;
            cnt++;
        }
        while(!stk.empty()){
            cout << stk.top();
            stk.pop();
        }
        cout << endl;
    }
    

    return 0;
}
