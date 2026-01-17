#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, s, t;
	while (1) {
		cin >> n;
		if (n == -1) break;

		int prev = 0, ans = 0;
		for (i=0;i<n;i++) {
			cin >> s >> t;
			ans += s * (t - prev);
			prev = t;
		}
		cout << ans << " miles" << endl;
	}
	return 0;
}
