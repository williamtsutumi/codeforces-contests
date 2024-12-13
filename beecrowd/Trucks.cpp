#include <iostream>
#include <vector>

using namespace std;

vector< vector<pair<int, int>> > graph;

int solve(int from, int to, int maxTemp)
{
    vector<pair<int, int>> nodo  = graph.at(from);
    for (auto ponte : nodo)
    {
        if (ponte.second >= maxTemp)
            maxTemp = min(maxTemp, solve(ponte.first, to));
    }
}

int main()
{
    int numIlhas, numPontes, numInputs;
    cin >> numIlhas >> numPontes >> numInputs;
    graph.resize(numIlhas);
    // Construindo o grafo
    while (numPontes--)
    {
        int from, to, pesoMax;
        cin >> from >> to >> pesoMax;
        graph.at(from).push_back(pair<int, int> (to, pesoMax));
        graph.at(to).push_back(pair<int, int> (from, pesoMax));
    }
    while (numInputs--)
    {
        int from, to; cin >> from >> to;
        cout << solve(from, to) << endl;
    }

    return 0;
}