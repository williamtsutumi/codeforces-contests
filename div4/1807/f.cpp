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
        int lines, cols; cin >> lines >> cols;
        pair<int,int> start, end;
        cin >> start.first >> start.second >> end.first >> end.second;

        string dir; cin >> dir;
        if (dir == "UR"){
        }
        else if (dir == "DL"){
        }
        else if (dir == "UL"){
        }

        while (start.first != end.first){
            start.first++;
            start.second++;
            if (start.first > lines){
                out++;
                start.first = 1;
            }
        }

        map<pair<int,int>, int> mp;
        while (mp[start.first][start.second] == 0){
            mp[start.first][start.second]++;
            start.first += lines;
            start.second += lines;
            out += start.second / cols;
            out++;
            start.second %= cols+1;
            start.first %= lines+1;
            if (start = end){
                ok = true;
                break;
            }
            if (mp[start.first][start.second] != 0){
                ok = false;
                break;
            }
        }
        if (ok) cout << out << '\n';
        elses cout << -1 << '\n';
    }

    return 0;
}
