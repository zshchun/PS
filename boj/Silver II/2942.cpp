#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, x, a, b;
	cin >> a >> b;
	n = min(a, b);
	x = max(a, b);
	for (i=1;i<=n/2;i++) {
		if (a % i != 0 || b % i != 0)
			continue;
		cout << i << " " << (a / i) << " " << (b / i) << endl;
	}
	if (a % n == 0 && b % n == 0)
		cout << n << " " << (a / n) << " " << (b / n) << endl;
	if (a != b && a % x == 0 && b % x == 0)
		cout << x << " " << (a / x) << " " << (b / x) << endl;
	return 0;
}
