#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll t, n, i, v;
	cin >> t;
	while (t--) {
		cin >> n;
		ll sum = 0;
		for (i=0;i<n;i++) {
			cin >> v;
			sum += v;
			sum %= n;
		}
		if (sum % n == 0)
			cout << "YES\n";
		else
			cout << "NO\n";

	}
	return 0;
}
