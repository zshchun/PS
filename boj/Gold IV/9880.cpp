#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
ll ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, i, x, y;
	cin >> N;
	vector<pa> a;
	ans = 0;
	for (i=0;i<N;i++) {
		cin >> x >> y;
		a.push_back(pa(x, y));
	}
	sort(a.begin(), a.end(), [&](pa lhs, pa rhs) {
		return lhs.second < rhs.second;
	});
	ll b = 0, c = 0;
	for (i=0;i<N;i++) {
		if (b >= c && b <= a[i].first) {
			b = a[i].second;
			ans++;
		} else if (b < c && c <= a[i].first) {
			c = a[i].second;
			ans++;
		} else if (b <= a[i].first) {
			b = a[i].second;
			ans++;
		} else if (c <= a[i].first) {
			c = a[i].second;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
