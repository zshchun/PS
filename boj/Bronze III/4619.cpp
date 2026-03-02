#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, n, i, j, k, ans, diff;
	while (cin >> b >> n) {
		if (!b && !n) break;
		if (n == 1) {
			cout << b << endl;
			continue;
		}
		ans = 1;
		diff = INF;
		for (i=1;i<=1000000;i++) {
			k = i;
			for (j=2;j<=n;j++)
				k *= i;
			if (abs(k-b) < diff) {
				diff = abs(k-b);
				ans = i;
			}
			if (k > 1000000) break;
		}
		cout << ans << endl;
	}
	return 0;
}
