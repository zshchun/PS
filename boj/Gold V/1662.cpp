#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	stack<int> q;
	int ans = 0, x;
	for (char &c : s) {
		if (c == ')') {
			x = 0;
			while (q.top() != -INF) {
				if (q.top() <= 0)
					x++;
				else
					x += q.top();
				q.pop();
			}
			q.pop();
			x = -q.top() * x;
			q.pop();
			if (x > 0)
				q.push(x);
		} else if (c == '(') {
			q.push(-INF);
		} else {
			q.push(-(c-'0'));
		}
	}

	while (!q.empty()) {
		if (q.top() <= 0)
			ans++;
		else
			ans += q.top();
		q.pop();
	}
	
	cout << ans << endl;
	return 0;
}
