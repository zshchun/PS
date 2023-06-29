#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, i, ans = 1;
	cin >> N;
	for (i=1;i<=N;i++) {
		ans *= i;
		ans %= 1000000000;
		while (ans % 10 == 0) {
			ans /= 10;
		}
	}
	cout << ans % 10 << endl;
	return 0;
}
