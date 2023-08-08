#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, v, T, N, ans;
	cin >> T;
	while (T--) {
		cin >> N;
		priority_queue<int, vector<int>, greater<int>> s;
		for (i=0;i<N;i++) {
			cin >> v;
			s.push(v);
		}
		ans = 0;
		while (s.size() > 1) {
			int x = s.top();
			s.pop();
			x += s.top();
			ans += x;
			s.pop();
			s.push(x);
		}
		cout << ans << endl;
	}
	return 0;
}
