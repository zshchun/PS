#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 1234567890123ULL

ll N, M, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, u, v, l, r, s, e;
	cin >> N >> M;
	vector<pa> a;
	for (i=0;i<N;i++) {
		cin >> u >> v;

		if (u > v)
			a.push_back(pa(v, u));
	}
	sort(a.begin(), a.end());

	l = r = 0;
	// sweeping
	for (i=0;i<a.size();i++) {
		tie(s, e) = a[i];
		if (s > r) {
			ans += e - s;
			l = s;
			r = e;
		} else if (e > r) {
			ans += e - r;
			r = e;
		}
	}
	ans = M + ans * 2;

	cout << ans << endl;

	return 0;
}
