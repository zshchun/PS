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
	ll i, price, sum, cur, cur_price;
	cin >> n >> m;
	vector<pa> a(n);
	for (i=0;i<n;i++)
		cin >> a[i].second >> a[i].first;
	sort(a.begin(), a.end(), [&](const pa lhs, const pa rhs) {
		if (lhs.first == rhs.first)
			return lhs.second > rhs.second;
		return lhs.first < rhs.first;
	});

	price = -1;
	cur = 0;
	sum = 0;
	for (i=0;i<n;i++) {
		if (a[i].first != price) {
			price = a[i].first;
			cur_price = a[i].first;
			sum += cur;
			cur = a[i].second;
		} else {
			cur_price += a[i].first;
			cur += a[i].second;
		}
		if (sum+cur >= m)
			ans = min(ans, cur_price);
	}
	if (ans == INF)
		ans = -1;
	cout << ans << endl;
	return 0;
}
