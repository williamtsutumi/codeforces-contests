#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int solve(vector<int> &input, int target)
{
    
}

int main()
{
    int numInputs, target;
    cin >> numInputs >> target;
    vector<int> input;
    input.resize(numInputs);
    for (int i = 0; i < numInputs; i++)
    {
        int in;
        cin >> in;
        input[i] = in;
    }
    cout << solve(input, target) << endl;

    return 0;
}