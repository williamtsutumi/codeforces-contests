#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const double INF = 1e9 + 7;

ld dotp(complex<ll> p1, complex<ll> p2){
    return p1.X * p2.Y - p2.X * p1.Y;
}

int main()
{
  int n; cin >> n;
  vector<P> vet(n);
  for(int i=0; i<n; i++){
    ll a,b; cin >> a >> b;
    // debug2(a,b)
    vet[i] = {a,b};
  }
  // for(int i=0; i<n; i++){
  //   debug2(vet[i].X, vet[i].Y)
  // }
  ll output = LONG_LONG_MAX;
  for(int i=0; i<n; i++){
    P p1 = vet[i];
    P p2 = vet[(i+1)%n];
    P p3 = vet[(i+2)%n];
    ll area = dotp(p1,p2);
    area += dotp(p2,p3);
    area += dotp(p3,p1);
    // debug(output)
    // debug(area)
    if (area == 0) continue;
    output = min(output, abs(area));
  }
  cout << output << endl;

  return 0;
}