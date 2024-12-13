#include <iostream>
#include <limits.h>
 
using namespace std;
 
int main() {
 
    int pessoas[4]; cin >> pessoas[1] >> pessoas[2] >> pessoas[3];
    int output = INT_MAX;
    int tempo = 0;
    for (int cafeteira = 1; cafeteira <= 3; cafeteira++){
        for (int pAndar = 1; pAndar <= 3; pAndar++){

            tempo += pessoas[pAndar] * (abs(cafeteira - pAndar)) * 2;
        }
        output = min(tempo, output);
        tempo = 0;
    }
 
    cout << output << endl;
    return 0;
}