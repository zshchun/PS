#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll c, k, p, ans = 0, i;
	cin >> c >> k >> p;
	for (i=0;i<=c;i++) {
		ans += k * i + p * i * i;
	}
	cout << ans << endl;
	return 0;
}
