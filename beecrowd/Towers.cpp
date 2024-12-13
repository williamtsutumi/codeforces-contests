#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> input;

int solve(int towers, int idx)
{
    
}

int main()
{
    int numInput; cin >> numInput;
    input.resize(numInput);
    for (int i = 0; i < numInput; i++)
    {
        int in; cin >> in;
        input[i] = in;
    }
    cout << solve() << endl;

    return 0;
}
