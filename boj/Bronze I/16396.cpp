#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

pa a[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, x, y, s, e, ans=0;
	cin >> n;
	s = e = 0;
	for (i=0;i<n;i++)
		cin >> a[i].first >> a[i].second;

	sort(a, a+n);
	for (i=0;i<n;i++) {
		tie(x, y) = a[i];
		if (e < x) {
			ans += e - s;
			s = x;
			e = y;
		} else {
			e = max(e, y);
		}
	}
	ans += e - s;
	
	cout << ans << endl;
	return 0;
}
