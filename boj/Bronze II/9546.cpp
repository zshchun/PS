#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
int main() {
	ll N, K, i, j, ans;
	cin >> N;
	while (N--) {
		ans = 1;
		cin >> K;
		for (j=1;j<K;j++) {
			ans = ans * 2 + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}
