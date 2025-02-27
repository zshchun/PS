#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 1234567890123ULL
ll a[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, k, i, ans = INF;
	cin >> n >> k;
	for (i=0;i<n;i++) {
		cin >> a[i];
		ans = min(a[i], ans);
	}
	sort(a, a+n);
	for (i=1;i<n;i++) {
		if (k >= (a[i] - a[i-1]) * i) {
			k -= (a[i] - a[i-1]) * i;
			ans = a[i];
		} else {
			ans += k / i;
			k = 0;
			break;
		}
	}
	ans += k / n;

	cout << ans << endl;

	return 0;
}
