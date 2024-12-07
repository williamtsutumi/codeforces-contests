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

    map<int,int> mp;
    for (int i=0; i<in.size(); i++){ mp[in[i]]++; }
    map<string,int> mp2;
    for (auto &[k,v]:mp){
        if (v % 2 == 1) mp2["odd"]++;
        else mp2["even"]++;
    }
    bool ok = true;
    for (auto &[k,v]:mp2){
        if (in.size() % 2 == 1){
            if (mp2["odd"] > 1){
                cout << "NO SOLUTION\n";
                return 0;
            }
        }
        else{
            if (mp2["odd"] > 0){
                cout << "NO SOLUTION\n";
                return 0;
            }
        }
    }

    char output[1000000];
    if (in.size() % 2 == 1 && mp2["odd"] == 1){
        for (auto &[k,v]:mp){
            if (v % 2 == 1) {
                output[in.size()/2] = k;
                break;
            }
        }
    }

    int sz = 0;
    for(auto &[k,v]:mp){
        for (int i=0; i<v/2; i++){
            output[sz] = k;
            output[in.size()-1-sz] = k;
            sz++;
        }
    }
    for (int i=0; i<in.size(); i++) cout << output[i];
    cout << endl;

    return 0;
}
