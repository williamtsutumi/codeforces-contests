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
        int nails; cin >> nails;
        int output = 0;
        for(int i=0; i<nails; i++){
            int h, size; cin >> h >> size;
            if (h > size) output++;
        }
        cout << output << endl;
    }

    return 0;
}
