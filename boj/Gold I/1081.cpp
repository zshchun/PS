#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
ll ans1, ans2;

ll get_sum(ll n) {
	if (n < 0) return 0;
	ll i, j, k, x = 0, ret = 0;
	for (i=1;n;i*=10) {
		k = n % 10;
		n /= 10;

		for (j=0;j<=9;j++) {
			if (j < k)
				ret += (n+1) * i * j;
			else if (j > k)
				ret += n * i * j;
			else
				ret += (n * i + x + 1) * j;
		}
		x += k * i;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll L, U;
	cin >> L >> U;

	ans1 = get_sum(L-1);
	ans2 = get_sum(U);

	cout << ans2 - ans1 << endl;

	return 0;
}
