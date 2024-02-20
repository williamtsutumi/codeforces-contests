#include <bits/stdc++.h>

using namespace std;

#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double
#define X real()
#define Y imag()

typedef long long ll;
typedef complex<ll> P;
const double INF = 1e9 + 7;

ll dotp(P p1, P p2){
    return (conj(p1)*p2).Y;
}

bool func(P p1, P p2, P p3){
    P aux1 = p3 - p1;
    P aux2 = p3 - p2;
    if(dotp(aux1, aux2) == 0)
        return min(p1.X, p2.X) <= p3.X && p3.X <= max(p1.X, p2.X)
        && min(p1.Y, p2.Y) <= p3.Y && p3.Y <= max(p1.Y, p2.Y);
    return false;
}

bool sides(P p1, P p2, P p3, P p4){
    P aux1 = p3 - p1;
    P aux2 = p3 - p2;
    if (dotp(aux1, aux2) > 0){
        return dotp(p4 - p1, p4 - p2) < 0;
    }
    if (dotp(aux1, aux2) < 0){
        return dotp(p4 - p1, p4 - p2) > 0;
    }
    return false;
}

bool intersect(P p1, P p2, P p3, P p4, ll &i){
    if(p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4){
        i++;
        return true;
    }
    
    if(func(p1, p2, p3) || func(p1, p2, p4)){
        i++;
        return true;
    }
    if(func(p3, p4, p1) || func(p3, p4, p2)){
        return true;
    }
    if (sides(p1, p2, p3, p4) && sides(p3, p4, p1, p2)){
        return true;
    }
    return false;
}

int main()
{
    ll vertices, points; cin >> vertices >> points;
    // debug2(vertices, points)
    vector<P> vet(vertices);
    for(ll i=0; i<vertices; i++){
        ll a,b; cin >> a >> b;
        vet[i] = {a,b};
    }
    for(ll i=0; i<points; i++){
        string out = "";
        ll a,b; cin >> a >> b;
        P p = {a,b};
        P p2 = {a, 1000000000};
        ll output = 0;
        for (ll j=0; j<vertices; j++){
            // debug(output)
            if (func(vet[j], vet[(j+1)%vertices], p))
            {
                out = "BOUNDARY";
                continue;
            }
            if (intersect(p, p2, vet[j], vet[(j+1)%vertices], j))
            {
                // debug2(vet[j].X, vet[j].Y)
                // debug2(vet[(j+1)%vertices].X, vet[(j+1)%vertices].Y)
                output++;
            }
        }
        if (out == "BOUNDARY"){
            cout << out << endl;
            continue;
        }
        if (output % 2==1) cout << "INSIDE" << endl;
        else cout << "OUTSIDE" << endl;
    }

    return 0;
}