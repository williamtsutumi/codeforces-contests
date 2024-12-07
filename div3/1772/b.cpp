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

bool check(vector<vector<int>> &in){
    return in[0][0] < in[0][1] && in[1][0] < in[1][1]
                && in[0][0] < in[1][0] && in[0][1] < in[1][1];
}

void rotate(vector<vector<int>> &in){
    swap(in[0][0], in[0][1]);
    swap(in[0][0], in[1][1]);
    swap(in[0][0], in[1][0]);
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        vector<vector<int>> in(2);
        in[0].resize(2);
        in[1].resize(2);
        cin >> in[0][0];
        cin >> in[0][1];
        cin >> in[1][0];
        cin >> in[1][1];

        if(check(in)){
            cout << "YES\n";
            continue;
        }
        rotate(in);
        if(check(in)){
            cout << "YES\n";
            continue;
        }
        rotate(in);
        if(check(in)){
            cout << "YES\n";
            continue;
        }
        rotate(in);
        if(check(in)){
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }

    return 0;
}
