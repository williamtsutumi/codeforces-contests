#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
 
    string input; cin >> input;
    int mod = 0;
    for (int i =0; i < input.size(); i++){
        string s = ""; s.push_back(input[i]);
        int num = stoi(s);
        mod += num;
    }
    mod = mod % 3;
    if (mod == 0) cout << 0 << endl;
    else if (mod == 1) cout << 1 << endl;
    else if (mod == 2) cout << 2 << endl;
 
    return 0;
}