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

string solve(vector<int> &v, int l, int r){
    string out;
    for (int i=r+1; i<v.size(); i++){
        out += to_string(v[i]);
    }
    for (int i=r; i>=l; i--){
        out += to_string(v[i]);
    }
    for (int i=0; i<l; i++){
        out += to_string(v[i]);
    }
    return out;
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        vector<int> v(n);
        int idx = -1;
        int idx2 = -1;
        for(int i=0; i<n; i++){
            cin >> v[i];
            if (n < 9 && v[i] == n) idx = i;
            else if (n >= 9 && v[i] == 9)
            if (v[i] == n-1) idx2 = i;
        } 
        string str;
        for(int i=0; i<n; i++) str += to_string(v[i]);
        debug(str);

        string outs = "0";
        int l, r;
        l = 0;
        r = 0;
        if (idx != 0){

            for (int i=0; i<idx; i++){
                string s = solve(v, i, idx-1);
                debug(s);
                if (s > outs){
                    outs = s;
                    l = i;
                    r = idx-1;
                }
            }
        }
        else{
            for (int i=0; i<idx2; i++){
                string s = solve(v, i, idx2-1);
                debug(s);
                if (s > outs){
                    outs = s;
                    l = i;
                    r = idx-1;
                }
            }
        }

        vector<int> out(n);
        int index = 0;
        for (int i=r+1; i<n; i++){
            out[index] = v[i];
            index++;
        }
        for (int i=r; i>=l; i--){
            out[index] = v[i];
            index++;
        }
        for (int i=0; i<l; i++){
            out[index] = v[i];
            index++;
        }
        for (int i=0; i<n; i++){
            cout << out[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
