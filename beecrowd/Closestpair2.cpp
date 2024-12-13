#include <bits/stdc++.h>

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

struct Point
{
	double x, y;
};

bool sortx(Point a, Point b)
{
	return a.x < b.x;
}

bool sorty(Point a, Point b)
{
	return a.y < b.y;
}

double dist(Point a, Point b)
{
	return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double brute(Point points[], int n)
{
	double mind = INF;
	// cout << "A menor distância entre os pontos do conjunto " << endl;
	for (int i = 0; i < n; i++)
	{
		// cout << points[i].x << " " << points[i].y << endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			mind = min(mind, dist(points[i], points[j]));
		}
	}
	// cout << "é " << mind << endl;
	return mind;
}

// O(n logn logn)
double c2p(Point points[], int n)
{
	if (n <= 3)
	{
		return brute(points, n);
	}
	else
	{
		int mid = n / 2;

		sort(points, points + n, sortx);

		double d1 = c2p(points, mid);
		double d2 = c2p(points + mid, n - mid);
		// cout << d1 << " " << d2 << endl;

		double eps = min(d1, d2);
		Point midpoint = points[mid];

		int j = 0;
		Point pontos_dis_eps[n];
		for (int i = 0; i < n; i++)
		{
			if (eps >= abs(points[i].x - midpoint.x))
			{
				pontos_dis_eps[j] = points[i];
				// cout << pontos_dis_eps[j].x << " " << pontos_dis_eps[j].y << endl;
				j++;
			}
		}

		sort(pontos_dis_eps, pontos_dis_eps + j, sorty);

		double menor_do_meio = INF;
		for (int i = 0; i < j; i++)
		{
			for (int k = i + 1; k < min(8, j); k++)
			{
				menor_do_meio = min(menor_do_meio, dist(pontos_dis_eps[i], pontos_dis_eps[k]));
			}
		}
		return min(eps, menor_do_meio);
	}
}

// O(n logn)
// i inclusivo, j exclusivo
double closestPair(Point x[], vector<Point> &y, int i, int j)
{
	if (j - i <= 3)
		return brute(x, j - i);

	int meio = (i + j) / 2;
	// cout << "meio: " << meio << endl;
	Point pontoMeio = x[meio];

	vector<Point> yLeft;
	vector<Point> yRight;
	for (int i = 0; i < y.size(); i++)
	{
		if (pontoMeio.x >= y[i].x)
			yLeft.push_back(y[i]);
		else
			yRight.push_back(y[i]);
	}

	double esq = closestPair(x, yLeft, i, meio);
	double dir = closestPair(x, yRight, meio + 1, j);
	// cout << "esq:" << esq << endl;
	// cout << "dir:" << dir << endl;
	double output = min(esq, dir);

	vector<Point> faixaMeio;
	for (int idx = i; idx < j; idx++)
	{
		if (abs(x[idx].x - pontoMeio.x) <= output)
			faixaMeio.push_back(x[idx]);
	}
	// cout << "faixaMeio: " << endl;
	// for (auto p : faixaMeio)
	// {
	// 	cout << "x: " << p.x << endl;
	// 	cout << "y: " << p.y << endl;
	// 	cout << "***************" << endl;
	// }
	int sizeFaixa = faixaMeio.size();
	int idx = 0;
	while (idx < sizeFaixa)
	{
		int k = idx;
		while ((k < sizeFaixa - 1) && (abs(faixaMeio[k].y - faixaMeio[k + 1].y) <= output))
		{
			output = min(output, dist(faixaMeio[k], faixaMeio[k + 1]));
			k++;
		}
		idx++;
	}
	return output;
}

int main()
{
	int n;
	cin >> n;
	while (n != 0)
	{
		Point points[10001];
		vector<Point> y;
		for (int i = 0; i < n; i++)
		{
			cin >> points[i].x;
			cin >> points[i].y;
			y.push_back(points[i]);
		}
		sort(y.begin(), y.end(), sorty);
		sort(points, points + n, sortx);
		double dis = closestPair(points, y, 0, n);
		if (dis < 10000)
			cout << fixed << setprecision(4) << dis << endl;
		else
			cout << "INFINITY" << endl;

		cin >> n;
	}
}