#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PER(i, a, b) for (int i = a; i >= b; i--)
#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const double INF = 1e9 + 7;

struct Node
{
    bool left = 1, right = 1, up = 1, down = 1;
};

Node graph[1002][1002];
bool visitado[1002][1002];

void printAresta(int x, int y)
{
    cout << "x: " << x << " y: " << y << endl;
    if (graph[x][y].left)
        cout << "L ";
    if (graph[x][y].right)
        cout << "R ";
    if (graph[x][y].up)
        cout << "U ";
    if (graph[x][y].down)
        cout << "D ";
    cout << endl;
}

void removeArestas(int currX, int currY, int prevX, int prevY)
{
    int start, its;
    if (currX == prevX)
    {
        start = min(currY, prevY);
        its = max(currY, prevY) - start - 1;

        REP (i, 0, its)
        {
            graph[currX][start + i].left = false;
            graph[currX - 1][start + i].right = false;
        }
    }
    else
    {
        start = min(currX, prevX);
        its = max(currX, prevX) - start - 1;
        REP (i, 0, its)
        {
            graph[start + i][currY].up = false;
            graph[start + i][currY - 1].down = false;
        }
    }
}

int bfs(int x, int y)
{
    queue<pii> q;
    q.push(MP(x, y));

    int area = 0;
    while (!q.empty())
    {
        int f = q.front().F;
        int s = q.front().S;
        q.pop();

        if (visitado[f][s])
            continue;
        visitado[f][s] = true;
        area++;

        if (graph[f][s].left)
            q.push(MP(f - 1, s));
        if (graph[f][s].right)
            q.push(MP(f + 1, s));
        if (graph[f][s].up)
            q.push(MP(f, s - 1));
        if (graph[f][s].down)
            q.push(MP(f, s + 1));
    }
    return area;
}

int solve()
{
    int output = -1;
    bfs(0, 0);
    REP (i, 0, 1001)
    {
        REP (j, 0, 1001)
        {
            if (visitado[i][j])
                continue;
            output = max(output, bfs(i, j));
        }
    }
    return output;
}

void removeArestaInvalida()
{
    REP (i, 0, 1001)
    {
        graph[0][i].left = false;
        graph[i][0].up = false;
        graph[1001][i].right = false;
        graph[i][1001].down = false;
    }
}

int main()
{
    removeArestaInvalida();

    int inputs;
    cin >> inputs;
    int currX, currY, prevX, prevY;
    cin >> prevX >> prevY;
    REP(i, 1, inputs)
    {
        cin >> currX >> currY;

        removeArestas(currX, currY, prevX, prevY);

        prevX = currX, prevY = currY;
    }
    // printAresta(2, 1);
    // printAresta(3, 1);
    // printAresta(4, 1);

    // printAresta(2, 2);
    // printAresta(3, 2);
    // printAresta(4, 2);

    // printAresta(2, 3);
    // printAresta(2, 4);
    // printAresta(2, 5);

    // printAresta(3, 5);
    // printAresta(4, 5);
    // printAresta(5, 5);
    // printAresta(6, 5);

    // printAresta(6, 4);
    // printAresta(6, 3);
    // printAresta(5, 4);
    // printAresta(5, 3);
    cout << solve() << endl;

    return 0;
}