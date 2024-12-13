#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> moves;

int solve(int disks, int from, int to, int aux)
{
    if (disks == 1)
    {
        moves.push_back(make_pair(from, to));
        return 1;
    }
    int to_aux = solve(disks - 1, from, aux, to);
    moves.push_back(make_pair(from, to));
    int aux_to = solve(disks - 1, aux, to, from);

    return 1 + to_aux + aux_to;
}

int main()
{
    int disks; cin >> disks;
    cout << solve(disks, 1, 3, 2) << endl;
    for (auto m : moves)
        cout << m.first << " " << m.second << endl;

    return 0;
}