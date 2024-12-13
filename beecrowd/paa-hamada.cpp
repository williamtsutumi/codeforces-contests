#include <bits/stdc++.h>

using namespace std;

int dp[51][51][51][101];

int solve(vector<int> &values, int bag1, int bag2, int bag3, int idx){
    if (idx >= values.size()) return 0;

    if (dp[bag1][bag2][bag3][idx] != -1) return dp[bag1][bag2][bag3][idx];

    int output = solve(values, bag1, bag2, bag3, idx + 1);

    if (values[idx] <= bag1)
        output = max(output, values[idx] + solve(values, bag1 - values[idx], bag2, bag3, idx + 1));
    
    if (values[idx] <= bag2)
        output = max(output, values[idx] + solve(values, bag1, bag2 - values[idx], bag3, idx + 1));

    if (values[idx] <= bag3)
        output = max(output, values[idx] + solve(values, bag1, bag2, bag3 - values[idx], idx + 1));

    dp[bag1][bag2][bag3][idx] = output;
    return output;
}

int main()
{
    int n, k; cin >> n >> k;
    vector<int> values(n);
    vector<int> bags(3, 0);
    for (int i=0; i<n; i++) cin >> values[i];
    for (int i=0; i<k; i++) cin >> bags[i];

    memset(dp, -1, sizeof(dp));

    cout << solve(values, bags[0], bags[1], bags[2], 0) << endl;

    return 0;
}