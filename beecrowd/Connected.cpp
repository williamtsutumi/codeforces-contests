#include <bits/stdc++.h>
 
using namespace std;
 
bool visitado[26];
bool conectados[26];
vector<vector<int>> grafo;

void solve(char nodo) {
    // cout << nodo << ',';
    nodo = nodo - 'a';
    visitado[nodo] = true;
    conectados[nodo] = true;
    
    for (int i = 0; i < grafo[nodo].size(); i++) {
        char proxNodo = grafo[nodo][i];
        if (visitado[proxNodo - 'a'] == false) {
            solve(proxNodo);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int runs; cin >> runs;
    for (int i = 1; i <= runs; i++) {
        int conexoes = 0;

        cout << "Case #" << i << ":" << endl;
        
        int nodos; cin >> nodos;
        int links; cin >> links;
        grafo.resize(nodos);
        grafo.clear();
        memset(visitado, 0, 26 * sizeof(bool));
        
        for (int i = 1; i <= links; i++) {
            char from; cin >> from;
            char to; cin >> to;
            grafo[from - 'a'].push_back(to);
            grafo[to - 'a'].push_back(from);
        }
        
        for (int i = 0; i < nodos; i++) {
            if (visitado[i] == false) {
                solve(i + 'a');

                for (int j = 0; j < 26; j++) {
                    if (conectados[j] == true) {
                        char c = j + 'a';
                        cout << c << ",";
                    }
                }
                memset(conectados, 0, 26 * sizeof(bool));
                cout << endl;
                conexoes++;
            }
        }

        cout << conexoes << " connected components" << endl << endl;
    }
 
    return 0;
}