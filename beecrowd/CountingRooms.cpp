#include <iostream>
#include <vector>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PER(i, a, b) for (int i = a; i >= b; i--)
#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
const double INF = 1e9 + 7;

vector<pair<vi, bool>> graph;

int make_address(int i, int j, int columns)
{
    return j + (i * columns);
}

void make_graph(vector<string> grid)
{
    int lines = grid.size() - 1;
    int columns = grid[0].length() - 1;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    REP(i, 0, lines)
    {
        REP(j, 0, columns)
        {
            if (grid[i][j] == '.')
            {
                REP(it, 0, 3)
                {
                    if (grid[i + dx[it]][j + dy[it]] == '.')
                    {
                        int from = make_address(i, j, columns + 1);
                        int to = make_address(i + dx[it], j + dy[it], columns + 1);
                        // debug2(i, j);
                        // debug2(i + dx[it], j + dy[it]);
                        // debug2(from ,to);
                        graph.at(from).first.PB(to);
                    }
                }
            }
        }
    }
}

void init_graph(int size)
{
    REP(i, 0, size - 1)
    {
        vi vet = {};
        graph[i] = MP(vet, false);
    }
}

int main()
{
    string input;
    int l, c; cin >> l >> c;
    graph.resize(make_address(l - 1, c - 1, c));
    init_graph(graph.size());

    vector<string> grid;
    grid.resize(l);
    for (int i = 0; i < l; i++)
    {
        cin >> input;
        grid[i] = input;
    }

    make_graph(grid);

    REP(i, 0, l - 1)
    {
        debug(graph[i].first.size() - 1);
        REP(its, 0, graph[i].first.size() - 1)
        {
            cout << "**************" << endl;
            cout << graph.at(i).first.at(its) << endl;
        }
    }
    // cout << solve() << endl;

    return 0;
}