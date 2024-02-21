#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long double ld;
typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

template<class T>
struct BIT{

  vector<T> bit;
  int n;

  BIT(int n) : bit(n+1){
    this->n = n;
  };

  void set(int idx, T v){
    for(int i = idx; i <= n; i += i & -i) bit[i] += v;
  }

  T get(int idx){
    ll v = 0;
    for(int i = idx; i ; i -= i & -i) v += bit[i];
    return v;
  }

  T get(int l, int r){
    return get(r) - get(l-1);
  }

  /*
  T lower_bound(T val){
    int ans = 0, sum = 0;
    for(int i = M - 1; i >= 0; i--){
      int x = ans + (1 << i);
      if(sum + bit[x] < val) 
        ans = x, sum += bit[x];
    }

    return ans + 1;
  }
  */
};

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        vector<int> in(n);
        for(int i=0; i<n; i++) cin >> in[i];

        BIT<ll> bit(n);
        ll out = 0;
        for(int i=1; i<=n; i++){
            int prev = bit.get(in[i-1], n);
            out += prev;

            bit.set(in[i-1], 1);
        }
        cout << out << '\n';
    }

    return 0;
}
