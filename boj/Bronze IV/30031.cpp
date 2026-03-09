#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, n, a, b, ans = 0;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> a >> b;
		if (a == 136) {
			ans += 1000;
		} else if (a == 142) {
			ans += 5000;
		} else if (a == 148) {
			ans += 10000;
		} else if (a == 154) {
			ans += 50000;
		}
	}
	cout << ans << endl;
	return 0;
}
