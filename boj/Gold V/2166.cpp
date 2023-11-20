#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N;
vector<pair<double,double>> p;

double ccw(double x1, double y1, double x2, double y2, double x3, double y3) {
	double ret = (x2-x1) * (y3-y1) - (y2-y1) * (x3-x1);
	return ret / 2.0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	double ans = 0.0;

	cin >> N;
	p.resize(N);

	for (i=0;i<N;i++)
		cin >> p[i].first >> p[i].second;

	for (i=1;i<N;i++)
		ans += ccw(p[0].first, p[0].second, p[i-1].first, p[i-1].second, p[i].first, p[i].second);

	cout << fixed << setprecision(1) << (double)abs(ans) << endl;

	return 0;
}
