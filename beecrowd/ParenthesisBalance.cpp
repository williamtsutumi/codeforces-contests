#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
 
    string input;
    
    while(cin >> input) {
        int qntParenteses = 0;
        
        for (int i = 0; i < input.length(); i++) {
            string carac = input.substr(i, 1);
            
            if (carac == "(") qntParenteses++;
            if (carac == ")") qntParenteses--;
            if (qntParenteses < 0) break;
        }
        
        if (qntParenteses == 0) cout << "correct" << endl;
        else cout << "incorrect" << endl;
    }
 
    return 0;
}