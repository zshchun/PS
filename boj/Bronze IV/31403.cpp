#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c, ans1, ans2;
	cin >> a >> b >>c;
	stack<int> q;
	ans1 = ans2 = a;
	ans1 += b;
	while (b) {
		q.push(b % 10);
		b /= 10;
	}

	while (!q.empty()) {
		int x = q.top();
		q.pop();
		ans2 = ans2 * 10 + x;
	}

	ans1 -= c;
	ans2 -= c;

	cout << ans1 << endl;
	cout << ans2 << endl;

	return 0;
}
