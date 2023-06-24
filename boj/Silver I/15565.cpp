#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

bool a[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, x, N, K, k = 0, ans = INF;
	cin >> N >> K;
	for (i=0;i<N;i++) {
		cin >> x;
		if (x == 1) a[i] = x;
	}

	// sliding window
	ll r = 0;
	for (i=0;i<N;i++) {
		while (k < K && r < N) {
			k += a[r];
			r++;
		}

		if (k == K && r - i < ans)
			ans = r - i;

		k -= a[i];
	}

	if (ans == INF)
		cout << "-1\n";
	else
		cout << ans << endl;

	return 0;
}
