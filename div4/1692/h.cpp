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

struct segtree{

  vector<int> seg;
  int n;
  const int NEUTRAL = INF;

  segtree(int _n) : seg(4*_n) {
    n = _n;
  };
  segtree(vector<int> &v) : seg(4*(int)v.size(), NEUTRAL) {
    n = (int)v.size();
    build(v);

  };

  int left(int node){
      return 2*node + 1;
  }
  int right(int node){
      return 2*node + 2;
  }

  void build(vector<int> &v, int node, int l, int r){
    if(r-l == 1){
      seg[node] = v[l];
      return;
    }
    int mid = (l+r)/2;
    build(v, left(node), l, mid);
    build(v, right(node), mid, r);

    seg[node] = max(seg[left(node)] , seg[right(node)]);
  }

  void build(vector<int> &v){
    build(v, 0, 0, n);
  }

  pair<int,pair<int,int>> combine(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
      if (a.first > b.first) return a;
      return b;
  }

  pair<int,pair<int,int>> query(int l, int r, int node, int nl, int nr){
    if(l <= nl && r >= nr) return {seg[node], {nl, nr}};
    if(nl >= r || nr <= l) return {-1, {-1, -1}};

    int mid = (nl+nr)/2;
    return combine(query(l, r, left(node), nl, mid),
      query(l, r, right(node), mid, nr));
  }
  pair<int, pair<int,int>> query(int l, int r){
    return query(l, r, 0, 0, n);
  }
  void update(int i, int v, int node, int l, int r){
    if(r-l == 1){
      seg[node] = v;
    }
    else{
      int mid = (l+r)/2;
      if(i < mid)
        update(i, v, left(node), l, mid);
      else
        update(i, v, right(node), mid, r);
      

      seg[node] = max(seg[left(node)] , seg[right(node)]);
    }
  }
  void update(int i, int v){
    update(i, v, 0, 0, n);
  }
};



vector<int> in, uniq;

pair<int, pair<int,int>> solve(){
    pair<int, pair<int,int>> out;

    int mx = INT_MIN;
    for(int i=0; i<uniq.size(); i++){
        int val = uniq[i];
        vector<int> v(in.size());
        for(int i=0; i<in.size(); i++){
            v[i] = (in[i] == val) ? 1 : -1;
        }
        debug(v);
        segtree seg(v);
        auto q = seg.query(0, in.size()-1);
        if (q.first > mx){
            mx = q.first;
            out = {val, {q.second.first, q.second.second}};
        }
    }
    return out;
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        int n; cin >> n;
        in.assign(n, 0);
        for(int i=0; i<n; i++) cin >> in[i];

        uniq = in;
        sort(uniq.begin(), uniq.end());
        uniq.resize(unique(uniq.begin(), uniq.end()) - uniq.begin());

        auto s = solve();

        cout << s.first << ' ' << s.second.first << ' ' << s.second.second << '\n';
    }

    return 0;
}
