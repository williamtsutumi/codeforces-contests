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

bool is_prime(int i){
    int its = ceil(sqrt(i));
    if (i % 2 == 0) return false;
    for (int j=2; j <its; j +=2){
        if (i % j == 0) return false;
    }

    return i >= 2;
}

int main()
{
    for (int i = 2; i< 1000000000; i++){
        if (is_prime(i)) cout << i << ",";
    }

    return 0;
}