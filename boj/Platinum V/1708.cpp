#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

struct point {
	ll x;
	ll y;
};

int N;
vector<point> p;
// CCW (Counter Clock Wise)
ll ccw(point a, point b, point c) {
	return (a.x * b.y) + (b.x * c.y) + (c.x * a.y) - ((b.x * a.y) + (c.x * b.y) + (a.x * c.y));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	point t;
	cin >> N;

	for (i=0;i<N;i++) {
		cin >> t.x >> t.y;
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
			return lhs.y == rhs.y ? lhs.x < rhs.x : lhs.y < rhs.y;
		return cc > 0; // counter clock wise
	});
	stack<point> s;
	s.push(p[0]);
	s.push(p[1]);
	// Convex Hull, Graham Scan
	for (i=2;i<N;i++) {
		while (s.size() >= 2) {
			point p2 = s.top();
			s.pop();
			point p1 = s.top();
			if (ccw(p1, p2, p[i]) > 0) {
				s.push(p2);
				break;
			}
		}
		s.push(p[i]);
	}

	cout << s.size() << endl;
	return 0;
}
