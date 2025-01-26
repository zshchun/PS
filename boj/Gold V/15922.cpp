#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, i, s1, e1, s2, e2, ans = 0;
	cin >> N;
	vector<pa> v(N);

	for (i=0;i<N;i++)
		cin >> v[i].first >> v[i].second;

	auto cur = v.begin();

	s1 = v[0].first;
	e1 = v[0].second;
	for (i=1;i<N;i++) {
		s2 = v[i].first;
		e2 = v[i].second;
		if (e1 > s2) {
			if (e2 > e1)
				e1 = e2;
		} else {
			ans += e1 - s1;
			s1 = s2;
			e1 = e2;
		}
	}
	ans += e1 - s1;

	cout << ans << endl;

	return 0;
}
