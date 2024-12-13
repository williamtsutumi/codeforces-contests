#include <iostream>

using namespace std;

int mdc(int a, int b)
{
    if (b == 0) return a;
    return abs(mdc(b, a%b));
}

int main()
{
    int inteira;
    int decimal;
    scanf("%d.%d", &inteira, &decimal);
    int r = 100 * inteira + decimal;
    cout << (36000 / mdc(36000, r)) << endl;
    return 0;
}