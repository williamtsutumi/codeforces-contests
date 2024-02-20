#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const double INF = 1e9 + 7;

int main()
{
    int runs; cin >> runs;
    while(runs--){
        int total, days, max; cin >> total >> days >> max;
        int count = 0;
        int output = 0;
        vector<int> counts;
        for(int i=0; i<total; i++){
            int temp; cin >> temp;
            if (temp <= max) count++;
            else if (count >= days){
                counts.push_back(count);
                count = 0;
            }
        }
        if (count >= days) counts.push_back(count);
        for(int a : counts){
            output += (1 + a-days+1) * (a-days+1) / 2;
        }
        cout << output << endl;
        // cout << "-----------------" << endl;
    }

    return 0;
}
