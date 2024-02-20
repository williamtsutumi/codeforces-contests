#include <bits/stdc++.h>

using namespace std;

#define PMOD(n,m) ((((n) % (m)) + m) % m)
#define F first
#define S second
#define PB push_back
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL);


typedef long long ll;
typedef pair<int, int> pii;
const int INF=1e9+7;
const ll INFLL=1e18+7;


int main(){
  FFIO;
  int n; cin >> n;
  vector<pii> ev(n);
  for(int i = 0; i < n; i++){
    cin >> ev[i].F >> ev[i].S;
  }
  sort(ev.begin(), ev.end(), [](pii a, pii b){
        if(a.S != b.S) return a.S < b.S;
        else return a.F < a.S;
      }
  );

  int lst = -1;
  int cnt = 0;
  for(int i = 0; i < n; i++){
    if(ev[i].F > lst){
      cnt++;
      lst = ev[i].S;
    }
  }
  cout << cnt << '\n';

}

