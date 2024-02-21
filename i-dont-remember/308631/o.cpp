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

#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

// returns the longest proper prefix array of pattern p
// where lps[i]=longest proper prefix which is also suffix of p[0...i]
vector<int> build_lps(string p) {
  int sz = p.size();
  vector<int> lps;
  lps.assign(sz + 1, 0);
  int j = 0;
  lps[0] = 0;
  for(int i = 1; i < sz; i++) {
    while(j >= 0 && p[i] != p[j]) {
      if(j >= 1) j = lps[j - 1];
      else j = -1;
    }
    j++;
    lps[i] = j;
  }
  return lps;
}

// returns matches in vector ans in 0-indexed
vector<int> kmp(vector<int> lps, string s, string p) {
    vector<int> ans;
  int psz = p.size(), sz = s.size();
  int j = 0;
  for(int i = 0; i < sz; i++) {
    while(j >= 0 && p[j] != s[i])
      if(j >= 1) j = lps[j - 1];
      else j = -1;
    j++;
    if(j == psz) {
      j = lps[j - 1];
      // pattern found in string s at position i-psz+1
      ans.push_back(i - psz + 1);
    }
    // after each loop we have j=longest common suffix of s[0..i] which is also prefix of p
  }
  return ans;
}

int main()
{
    int lin, col, l, c; cin >> lin >> col >> l >> c;
    vector<string> lines(lin);
    for(int i=0; i<lin; i++){
        cin >> lines[i];
    }
    vector<string> mat(l);
    for(int i=0; i<l; i++){
        cin >> mat[i];
    }
    vector<vector<int>> first(lin);
    for(int i=0; i<lin; i++){
        first[i] = kmp(build_lps(mat[0] + "#" + lines[i]), mat[0], lines[i]);
    }
    for(int i=0; i<first.size(); i++){
        vector<int> aux = first[i];
        for(int j=0; j<aux.size(); j++){
            
            for(int k=1; k<c; k++){
                if (kmp().size() == 0) break;
                else if (k == c){
                    cout << i << " " << j << endl;
                    return 0;
                }
            }
        }
    }
    cout << "-1 -1" << endl;
    return 0;
}