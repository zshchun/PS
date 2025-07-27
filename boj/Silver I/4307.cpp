#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, i, d, v, n, mn, mx;
	cin >> T;
	while (T--) {
		cin >> d >> n;
		mn = 0;
		mx = 0;
		for (i=0;i<n;i++) {
			cin >> v;
			mn = max(mn, min(v, d-v));
			mx = max({mx, v, d-v});
		}
		cout << mn << ' ' << mx << endl;
	}
	return 0;
}
