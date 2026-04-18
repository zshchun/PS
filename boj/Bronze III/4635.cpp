#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, v, s, t, ans, prev;
	while (1) {
		prev = ans = 0;
		cin >> n;
		if (n == -1) break;
		for (i=0;i<n;i++) {
			cin >> s >> t;
			ans += s * (t - prev);
			prev = t;
		}
		cout << ans << " miles\n";
	}
	return 0;
}
