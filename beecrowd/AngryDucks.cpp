#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define PER(i, a, b) for (int i = a; i >= b; i--)
#define PMOD(n, m) ((((n) % (m)) + (m)) % (m))
#define debug(x) cerr << #x << " = " << x << endl;
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define ld long double

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
const double INF = 1e9 + 7;

const ld G = 9.80665L;
const ld PI = 3.14159L;

ld solve(ld angle, ld speed, ld height)
{
	ld vx = speed * cosl(angle * PI / 180.0L);
	ld vy = speed * sinl(angle * PI / 180.0L);
	ld tempoSubida = vy / G;
	ld hmax = vy * tempoSubida / 2.0L;
	ld tempoDescida = sqrtl(2.0L * (height + hmax) / G);

	return vx * (tempoSubida + tempoDescida);
}

int main()
{
	cout << fixed << setprecision(5);

	int start, endi;
	ld height;
	cin >> height >> start >> endi;

	int inputs;
	cin >> inputs;
	while (inputs--)
	{
		ld angle, speed;
		cin >> angle >> speed;

		ld s = solve(angle, speed, height);
		if (start <= s && s <= endi)
			cout << s << " -> DUCK" << endl;
		else
			cout << s << " -> NUCK" << endl;
	}
	return 0;
}