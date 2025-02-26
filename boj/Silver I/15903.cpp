#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, x, y, z, n, m, ans = 0;
	cin >> n >> m;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for (i=0;i<n;i++) {
		cin >> x;
		pq.push(x);
	}

	for (i=0;i<m;i++) {
		x = pq.top(); pq.pop();
		y = pq.top(); pq.pop();
		z = x + y;
		pq.push(z);
		pq.push(z);
	}

	while (!pq.empty()) {
		ans += pq.top();
		pq.pop();
	}
	cout << ans << endl;

	return 0;
}
