#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(vector<pair<int, int>> &input, int target)
{
    sort(input.begin(), input.end());

    auto esq = input.begin();
    auto dir = input.end() - 1;
    int sum = (*esq).first + (*dir).first;
    bool achou = false;

    while (dir != esq)
    {
        sum = (*esq).first + (*dir).first;
        if (sum < target)
            esq++;
        else if (sum > target)
            dir--;
        else
        {
            achou = true;
            break;
        }
    }
    if (achou)
        cout << min((*esq).second, (*dir).second) << " " << max((*esq).second, (*dir).second) << endl;
    else
        cout << "IMPOSSIBLE" << endl;

}

int main()
{
    int num_inputs, target; cin >> num_inputs >> target;
    vector<pair<int, int>> input;
    for (int i = 1; i <= num_inputs; i++)
    {
        int in; cin >> in;
        input.push_back(make_pair(in, i));
    }
    solve(input, target);

    return 0;
}