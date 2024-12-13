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

const int maxL = 1002;
const int maxC = 1002;
const int maxSqr = maxL * maxC;
vi graph[maxL * maxC];
bool visitado[maxL * maxC];

void printNode(int idx)
{
    cout << "*****************" << endl;
    for (int i : graph[idx])
    {
        if (i == idx + 1)
            cout << "Direita ";
        if (i == idx - 1)
            cout << "Esquerda ";
        if (i == idx + maxC)
            cout << "Baixo ";
        if (i == idx - maxC)
            cout << "Cima ";
    }
    cout << endl;
}

void make_graph()
{
    for (int i = 0; i < maxSqr; i++)
    {
        // nao esta na primeira coluna
        if (i % maxC)
            graph[i].PB(i - 1);
        // nao esta na ultima coluna
        if ((i + 1) % maxC)
            graph[i].PB(i + 1);
        // nao esta na primeira linha
        if (i - maxC >= 0)
            graph[i].PB(i - maxC);
        // nao esta na ultima linha
        if (i + maxC < maxSqr)
            graph[i].PB(i + maxC);
    }
}

int bfs(int i)
{
    queue<int> q;
    q.push(i);

    int top, area = 1;
    visitado[i] = true;
    while (!q.empty())
    {
        top = q.front();
        q.pop();

        for (int visinho : graph[top])
        {
            if (visitado[visinho])
                continue;
            visitado[visinho] = true;

            q.push(visinho);
            area++;
        }
    }
    return area;
}

int solve()
{
    int output = INT_MIN;
    bfs(0);
    for (int i = 0; i < maxSqr; i++)
    {
        if (visitado[i])
            continue;

        output = max(output, bfs(i));
    }
    return output;
}

void removeArestas(int currX, int currY, int prevX, int prevY)
{
    int its, prev_node, from, to, dxy;
    vi::iterator toErase;
    if (currY == prevY)
    {
        its = abs(currX - prevX);
        prev_node = maxC;
        dxy = 1;
        from = (min(currX, prevX)) + (maxC * (currY));
    }
    else if (currX == prevX)
    {
        its = abs(currY - prevY);
        prev_node = 1;
        dxy = maxC;
        from = (currX) + (maxC * (min(currY, prevY)));
    }

    REP(i, 1, its)
    {
        to = from - prev_node;

        toErase = find(graph[from].begin(), graph[from].end(), to);
        if (toErase != graph[from].end())
            graph[from].erase(toErase);
        
        toErase = find(graph[to].begin(), graph[to].end(), from);
        if (toErase != graph[to].end())
            graph[to].erase(toErase);

        from += dxy;
    }
}

int main()
{
    make_graph();

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
    cout << solve() << endl;

    return 0;
}