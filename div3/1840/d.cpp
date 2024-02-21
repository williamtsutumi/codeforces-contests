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

ld vals[200001];

int auxi(int indexes[], int t){
	ld a = vals[0];
	ld b = vals[indexes[0]];
	// debug2(a,b)
	int output1 = ceil(abs(a - b) / 2.0L);

	a = vals[indexes[0] + 1];
	b = vals[indexes[1]];
	// debug2(a,b)
	int output2 = ceil(abs(a - b) / 2.0L);

	a = vals[indexes[1] + 1];
	// debug(a)
	b = vals[t-1];
	// debug2(a,b)
	int output3 = ceil(abs(a - b) / 2.0L);

	int c = (output1 > output2) ? output1 : output2;
	return (c > output3) ? c : output3;
}

int solve(int t){
	// debug(t)
	sort(vals , vals + t);
	ld mini = vals[0];
	ld maxi = vals[t - 1];
	ld region_size = (maxi - mini) / 3.0L;
	// debug2(min, max)
	// debug(region_size)
	int indexes[2];
	int aux = 0;
	for(int i=0; i<t; i++){
		if(vals[i] > region_size){
			// debug(i)
			// debug(abs(vals[i] -region_size))
			// debug(abs(vals[i-1] -region_size))
			// cout << "-----------"<<endl;
			indexes[aux] = i-1;
			aux++;
			region_size *= 2;
		}
	}
	// debug2(indexes[0], indexes[1])
	int output = auxi(indexes, t);

	indexes[0] = max(0, indexes[0]-1);
	output = min(output, auxi(indexes, t));

	indexes[0] = min(t-1, indexes[0]+2);
	output = min(output, auxi(indexes, t));

	indexes[0] = max(0, indexes[0]-1);
	indexes[1] = max(0, indexes[1]-1);
	output = min(output, auxi(indexes, t));

	indexes[1] = min(t-1, indexes[1]+2);
	output = min(output, auxi(indexes, t));
	return output;
}

int main()
{
	int runs; cin >> runs;
	while(runs--){
		map<int, int> mp;
	    int toys; cin >> toys;
	    for(int i = 0; i < toys; i++){
			cin >> vals[i];
			mp[vals[i]]++;
	    }
		if (mp.size() <= 3){
			cout<<0<<endl;
			continue;
		}
		cout << solve(toys)<<endl;
		// cout << "--------------" <<endl;
	}
	return 0;
}
