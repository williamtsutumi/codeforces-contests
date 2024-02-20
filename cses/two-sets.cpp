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
    int n; cin >> n;
    int calc = (n+1)*n/2;
    if (calc%2==1) cout << "NO\n";
    else{
        cout << "YES\n";
        bool done[n+1];
        memset(done, false, sizeof(done));

        vector<int> s1;
        vector<int> s2;
        if (n%4 != 0){
            s1 = {1,2};
            s2 = {3};
            for (int i=4; i<=n; i+=4){
                s1.push_back(i);
                s2.push_back(i+1);
                s2.push_back(i+2);
                s1.push_back(i+3);
            }
        }
        else{
            for (int i=1; i<=n; i+=4){
                s1.push_back(i);
                s2.push_back(i+1);
                s2.push_back(i+2);
                s1.push_back(i+3);
            }
        }



        cout << s1.size() << endl;
        for (int i=0; i<s1.size(); i++){
            cout << s1[i] << ' ';
        }
        cout << endl;
        cout << s2.size() << endl;
        for (int i=0; i<s2.size(); i++) cout << s2[i] << ' ';
        cout << endl;
    }

    return 0;
}
