#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, m, v, i, ans = 1;
	cin >> n >> m;
	for (i=0;i<n;i++) {
		cin >> v;
		ans *= v;
		ans %= m;
	}
	cout << ans << endl;
	return 0;
}
