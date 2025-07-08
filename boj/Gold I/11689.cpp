#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

ll ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, i, ans;
	cin >> n;
	ans = n;
	// euler's phi
	for (i=2;i*i<=n;i++) {
		if (n % i == 0) {
			// ans = ans / i * (i - 1);
			ans -= ans / i;
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) ans -= ans / n;

	cout << ans << endl;
	return 0;
}
