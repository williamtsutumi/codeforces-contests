#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
 
    int pessoas; cin >> pessoas;
    int classif; cin >> classif;
    vector<int> pontos;
    int ponto;
    while (cin >> ponto){
        pontos.push_back(1000-ponto);
    }
    sort(pontos.begin() , pontos.end());
    cout << "vector" << endl;
    for (int p : pontos){
        cout  << p << endl;
    }
    while (classif < pontos.size() && pontos.at(classif-1) == pontos.at(classif)){
        classif++;
    }
    if (pessoas < classif) cout << pessoas << endl;
    else cout << classif << endl;
    
 
    return 0;
}