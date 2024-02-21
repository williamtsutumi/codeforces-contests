#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
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

vector<string> read(){
    string line;
    vector<string> out;
    while(getline(cin, line)){
        stringstream ss(line);
        string str;
        while(getline(ss, str, ' ')){
            out.push_back(str);
        }
    }
    return out;
}

int main()
{
    FFIO;
    int n; cin >> n;
    while (n--){
        string in; cin >> in;
        int out = 0;
        if (in[0] == 'B' || in[in.size() -1] == 'B'){
            for (int i=0; i<in.size(); i++){
                if (in[i] == 'A') out++;
            }
        }
        else{
            int sum = 0, size = 0, mn = INT_MAX, count = 0;
            for (int i=0; i<in.size(); i++){
                if (in[i] == 'A'){
                    size++;
                }
                else{
                    count++;
                    sum += size;
                    mn = min(mn, size);
                    size = 0;
                }
            }
            sum += size;
            mn = min(mn, size);
            if (count == 0) out = 0;
            else out = sum - mn;
        }
        cout << out << '\n';
    }

    return 0;
}
