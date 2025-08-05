#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789012LL
ll n, m, ans = INF;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, price, sum, cur;
	cin >> n >> m;
	vector<pa> a(n);

	for (i=0;i<n;i++)
		cin >> a[i].second >> a[i].first;

	sort(a.begin(), a.end(), [&](const pa lhs, const pa rhs) {
		if (lhs.first == rhs.first)
			return lhs.second > rhs.second;
		return lhs.first < rhs.first;
	});


	price = sum = cur = 0;
	for (i=0;i<n;i++) {
		sum += a[i].second;
		if (i && a[i].first == a[i-1].first)
			price += a[i].first;
		else
			price = a[i].first;
		if (sum >= m)
			ans = min(ans, price);
	}

	if (ans == INF)
		ans = -1;

	cout << ans << endl;
	return 0;
}
