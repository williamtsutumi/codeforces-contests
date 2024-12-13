#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool isPrime(long long num)
{
    long long toCheck = floor(sqrt(num));
    for (long long i = 2; i <= toCheck; i++)
    {
        if (num % i == 0)
            return false;
    }
    return num >= 2;
}

vector<long long> divisoresPrimos(long long num)
{
    vector<long long> d;
    long long toCheck = floor(sqrt(num));
    for (long long i = 2; i <= toCheck; i++)
    {
        if (num % i == 0)
        {
            if (isPrime(i))
                d.push_back(i);

            long long other = num / i;
            if (isPrime(other))
                d.push_back(other);
        }
    }
    return d;
}

int main()
{
    long long num;
    cin >> num;
    long long output = 0;

    vector<long long> d = divisoresPrimos(num);
    if (isPrime(num))
        output = 0;
    else
        output = pow(2, d.size()) - d.size() - 1;

    cout << output << endl;

    return 0;
}