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
    string in; cin >> in;

    int cnt[1000];
    memset(cnt, 0, sizeof cnt);
    set<string> output;
    sort(in.begin(), in.end());
    do {
        output.insert(in);
    } while(next_permutation(in.begin(), in.end()));
    cout << output.size() << '\n';
    for (auto it=output.begin(); it != output.end(); it++){
        cout << *it << '\n';
    }

    return 0;
}
