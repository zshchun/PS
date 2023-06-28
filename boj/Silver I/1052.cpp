#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, K, i, j, ans = 0;
	cin >> N >> K;
	if (N <= K) {
		cout << "0\n";
		return 0;
	}
	for (i=N;;i++) {
		j = __builtin_popcount(i);
		if (j <= K) break;
		ans++;
	}
	cout << ans << endl;

	return 0;
}
