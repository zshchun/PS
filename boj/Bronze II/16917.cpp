#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c, x, y, mn, ans = 0;
	cin >> a >> b >> c >> x >> y;
	mn = min(x, y);

	if (a + b > c * 2)
		ans += mn * c * 2;
	else
		ans += mn * (a + b);
	x -= mn; y -= mn;
	if (a > c * 2)
		ans += x * c * 2;
	else
		ans += x * a;
	if (b > c * 2)
		ans += y * c * 2;
	else
		ans += y * b;
	cout << ans << endl;
	return 0;
}
