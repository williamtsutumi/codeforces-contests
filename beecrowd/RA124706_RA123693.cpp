/**
 * @file Trabalho de Projeto de Análise de Algoritmos - Par mais próximo
 * @author William Kenzo Tsutumi RA: 124706
 * @author William Davi Santo Vernaschi RA: 123693
 */

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
			for (int k = i + 1; k < min(8+(i+1), j); k++) // de i+1 até 8+i+1
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
	int size = j - i;
	if (size <= 3)
		return brute(x, size);

	int meio = (i + j) / 2;
	Point pontoMeio = x[meio];

	vector<Point> yLeft;
	vector<Point> yRight;
	for (int i = 0; i < size; i++)
	{
		if (pontoMeio.x >= y[i].x)
			yLeft.push_back(y[i]);
		else
			yRight.push_back(y[i]);
	}

	double esq = closestPair(x, yLeft, i, meio);
	double dir = closestPair(x, yRight, meio + 1, j);
	double output = min(esq, dir);

	vector<Point> faixaMeio;

	for (int idx = i; idx < j; idx++)
	  if (abs(x[idx].x - pontoMeio.x) <= output)
			faixaMeio.push_back(x[idx]);

	int sizeFaixa = faixaMeio.size();
	int idx = 0;

  for(int i = 0; i < sizeFaixa; i++){
    for(int j = i+1; j < min(i+1+8, sizeFaixa); j++){
		output = min(output, dist(faixaMeio[i], faixaMeio[j])); // de i+1 até 8+i+1
    }
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
    	//double dis = c2p(points, n);
		if (dis < 10000)
			cout << fixed << setprecision(4) << dis << endl;
		else
			cout << "INFINITY" << endl;

		cin >> n;
	}
}
