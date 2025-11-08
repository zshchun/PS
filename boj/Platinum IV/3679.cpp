#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
struct point { ll x; ll y; ll n; };

// CCW(Counter Clock Wise)
ll ccw(point a, point b, point c) {
	return (a.x * b.y) + (b.x * c.y) + (c.x * a.y) - ((b.x * a.y) + (c.x * b.y) + (a.x * c.y));
}
ll dist(point a, point b) {
	ll dx = a.x - b.x;
	ll dy = a.y - b.y;
	return dx * dx + dy * dy;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int c, n, i;
	point t;
	cin >> c;
	cin.ignore();
	while (c--) {
		vector<point> p;
		cin >> n;
		for (i=0;i<n;i++) {
			cin >> t.x >> t.y;
			t.n = i;
			p.push_back(t);
		}

		sort(p.begin(), p.end(), [&](point &lhs, point &rhs) {
			if (lhs.y == rhs.y)
				return lhs.x < rhs.x;
			return lhs.y < rhs.y;
		});

		sort(p.begin()+1, p.end(), [&](point &lhs, point &rhs) {
			ll cc = ccw(p[0], lhs, rhs);
			if (cc == 0)
				return dist(p[0], lhs) < dist(p[0], rhs);
			return cc > 0;
		});
		int e = n - 1;
		while (e >= 2 && ccw(p[0], p[e-1], p[e]) == 0) e--;
		reverse(p.begin()+e, p.end());

		for (point &o : p)
			cout << o.n << ' ';
		cout << endl;
	}
	return 0;
}
