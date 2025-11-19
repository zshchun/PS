#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 1234567890
#define Y first
#define X second
vector<pa> v;
double ans;
int n, cnt;

// CCW, Counter Clock Wise
double ccw(pa a, pa b, pa c) {
	return (a.X * b.Y + b.X * c.Y + c.X * a.Y) - (b.X * a.Y + c.X * b.Y + a.X * c.Y);
}

double distance(pa a, pa b) {
	return sqrt((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, sz;
	while (1) {
		ans = INF;
		cin >> n;
		if (n == 0) break;
		v.resize(n);
		for (i=0;i<n;i++)
			cin >> v[i].X >> v[i].Y;
		sort(v.begin(), v.end());
		sort(v.begin()+1, v.end(), [&](pa &lhs, pa &rhs) {
			ll cc = ccw(v[0], lhs, rhs);
			if (cc == 0)
				return lhs.Y == rhs.Y ? lhs.X < rhs.X : lhs.Y < rhs.Y;
			return cc > 0;
		});

		// Convex Hull, Graham Scan
		vector<pa> s;
		s.push_back(v[0]);
		s.push_back(v[1]);
		for (i=2;i<n;i++) {
			while (s.size() >= 2) {
				pa p2 = s.back();
				s.pop_back();
				pa p1 = s.back();
				if (ccw(p1, p2, v[i]) > 0) {
					s.push_back(p2);
					break;
				}
			}
			s.push_back(v[i]);
		}
		sz = s.size();
		for (i=0;i<sz;i++) {
			double dist = distance(s[i], s[(i+1) % sz]);
			double mx = 0;
			for (j=0;j<sz;j++) {
				if (j == i || j == (i+1) % sz) continue;
				ll res = abs(ccw(s[i], s[(i+1) % sz], s[j]));
				mx = max(mx, (double)res / dist);
			}
			ans = min(ans, mx);

		}
		ans *= 100;
		if (ans - (ll)ans > (1e-12)) {
			ans++;
			ans = (ll)ans;
		}
		ans /= 100;
		cout << "Case " << ++cnt << ": " << fixed << setprecision(2) << ans << endl;
	}

	return 0;
}
