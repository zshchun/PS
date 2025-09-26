#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, p, t, ans, n;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> p >> t;
		ans = p;
		ans += t / 4 - t / 7;
		cout << ans << endl;
	}
	return 0;
}
