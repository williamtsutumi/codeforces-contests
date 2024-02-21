#ifdef ONLINE_JUDGE
    #define debug(x...)
#else
    #include "../../debug.h"
#endif

#include <bits/stdc++.h>

using namespace std;

#define FFIO ios_base::sync_with_stdio(false);cin.tie(NULL)

typedef long double ld;
typedef long long ll;
typedef complex<ll> P;
const ll INF = 1e9 + 7;

bool palindr(string time){
    string str;
    for (int i=time.size()-1; i>=0; i--){
        str.push_back(time[i]);
    }

    return str == time;
}

void addtime(string &str, int time){
    int mn = stoi(str.substr(3, 2));
    int hr = stoi(str.substr(0, 2));

    mn += time % 60;
    int addhr = 0;
    if (mn >= 60){
        mn %= 60;
        addhr = 1;
    }
    mn %= 60;

    hr += time/60 + addhr;
    hr %= 24;

    str[0] = (char)((hr / 10) + (int)'0');
    str[1] = (char)((hr % 10) + (int)'0');

    str[3] = (char)((mn / 10) + (int)'0');
    str[4] = (char)((mn % 10) + (int)'0');
}

int main()
{
    FFIO;
    int r; cin >> r;
    while(r--){
        string time; cin >> time;
        int span; cin >> span;

        set<string> st;
        ll out = 0;
        while(st.find(time) == st.end()){
            st.insert(time);
            addtime(time, span);
            if (palindr(time)) out++;
        }
        cout << out << '\n';
    }

    return 0;
}
