#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, M, i, ans;
	cin >> N >> M;
	vector<ll> a(N);

	for (i=0;i<N;i++)
		cin >> a[i];

	sort(a.begin(), a.end());
	ans = a.back() - a.front();

	for (auto it = a.begin(); it != a.end(); it++) {
		ll next = *it + M;
		auto it2 = lower_bound(it, a.end(), next);
		if (it2 != a.end()) {
			ans = min(ans, *it2 - *it);
		}
	}

	cout << ans << endl;
	return 0;
}
