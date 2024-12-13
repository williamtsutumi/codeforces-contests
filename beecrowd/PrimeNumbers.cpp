#include <iostream>
#include <vector>

#define ll long long

using namespace std;

ll solve(l n, vector<ll> &primes)
{
    
}

int main()
{
    ll n, numPrimes; cin >> n >> numPrimes;
    vector<ll> primes;
    primes.resize(numPrimes);
    for (ll i = 0; i < numPrimes; i++)
    {
        ll p; cin >> p;
        primes[i] = p;
    }
    cout << solve(n, primes) << endl;

    return 0;
}