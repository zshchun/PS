#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, K, v, ans;
	cin >> T;
	while (T--) {
		cin >> K;
		ans = 0;
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		for (i=0;i<K;i++) {
			cin >> v;
			pq.push(v);
		}
		while (pq.size() > 1) {
			ll a = pq.top(); pq.pop();
			ll b = pq.top(); pq.pop();
			ans += a + b;
			pq.push(a + b);
		}
		cout << ans << endl;
	}

	return 0;
}
