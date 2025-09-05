#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, h, i, t, v, ans = 0;
	cin >> n >> h >> t;
	priority_queue<int> pq;

	for (i=0;i<n;i++) {
		cin >> v;
		pq.push(v);
	}
	while (t && pq.top() >= h) {
		if (pq.top() == 1) break;
		int x = pq.top();
		pq.pop();
		x /= 2;
		pq.push(x);
		t--;
		ans++;
	}
	if (pq.top() >= h) {
		cout << "NO\n";
		cout << pq.top() << endl;
	} else {
		cout << "YES\n";
		cout << ans << endl;
	}

	return 0;
}
