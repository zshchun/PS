#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, d, x, y, j, mx;
	cin >> T;
	for (j=0;j<T;j++) {
		cin >> x >> y;
		d = y - x;
		mx = sqrt(d);
		ans = mx * 2;
		if (mx * mx == d)
			ans--;
		else if (d > mx * mx + mx)
			ans++;

		cout << ans << endl;
	}
	return 0;
}
