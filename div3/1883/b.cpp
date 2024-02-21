#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int main()
{
    int runs; cin >> runs;
    while (runs--){
        int size, remove; cin >> size >> remove;
        string in; cin >> in;

        map<int,int> mp;
        for (int i=0; i<in.size(); i++) mp[in[i]]++;

        int odds = 0;
        for (auto [f, s] : mp){
            if (s % 2 == 1) odds++;
        }

        int tam = in.size() - remove;
        if (tam % 2 == 0){
            if (remove >= odds && (abs(remove - odds) % 2 == 0)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        else{
            if (remove >= odds - 1 && (abs(remove - odds) % 2 == 1)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }

    return 0;
}
