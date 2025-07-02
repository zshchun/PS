#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll a[2001];
ll b[2001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j, k, n, m, v, ans = 1, g;
	bool exceed = false;
	cin >> n;
	for (i=0;i<n;i++)
		cin >> a[i];

	cin >> m;
	for (i=0;i<m;i++)
		cin >> b[i];

	for (i=0;i<n;i++) {
		for (j=0;j<m;j++) {
			ll g = gcd(a[i], b[j]);
			if (g > 1) {
				ans *= g;
				if (ans >= 1000000000)
					exceed = true;
				ans %= 1000000000;
				a[i] /= g;
				b[j] /= g;
			}
		}
	}

	cout.fill('0');
	if (exceed)
		cout << setw(9) << ans << endl;
	else
		cout << ans << endl;

	return 0;
}
