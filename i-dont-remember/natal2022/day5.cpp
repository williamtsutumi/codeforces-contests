#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "/mnt/c/Projetos/beecrowd/debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

int main()
{
    vector<string> input;
    string in;
    do {
        getline(cin, in);
        input.push_back(in);
    } while (in[1] != '1');

    string last_line = input[input.size() - 1];
    int num_stacks = last_line[last_line.length() - 3] - '0';
    int max_stack_size = input.size() - 1;
    vector<stack<char>> stacks(num_stacks);
    for (int i=0; i<num_stacks; i++){
        debug(i);
        for (int j=0; j<max_stack_size; j++){
            char ch = input[max_stack_size - 1 - j][1 + 4*i];
            debug(ch);
            if (ch == ' ') continue;
            stacks[i].push(ch);
        }
    }
    getline(cin, in);
    string useless;
    while (cin >> useless){
        int count, from, to;
        
        cin >> count;
        cin >> useless;
        cin >> from;
        cin >> useless;
        cin >> to;
        debug(count, from, to);
        stack<char> aux;
        for (int i=0; i<count; i++){
            aux.push(stacks[from-1].top());
            stacks[from-1].pop();
        }
        for (int i=0; i<count; i++){
            stacks[to-1].push(aux.top());
            aux.pop();
        }
    }
    cout << "A" << endl;
    string output = "";
    for (int i=0; i<num_stacks; i++){
        output += stacks[i].top();
    }
    cout << output << endl;

    return 0;
}
