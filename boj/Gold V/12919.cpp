#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int ans = 0;
	string s, t;
	queue<string> q;
	cin >> s >> t;
	q.push(t);
	while (!q.empty()) {
		string r = q.front();
		q.pop();
		if (r == s) {
			ans = 1;
			break;
		}
		if (r.size() <= 1) continue;
		if (r.back() == 'A')
			q.push(r.substr(0, r.size()-1));
		if (r.front() == 'B') {
			reverse(r.begin(), r.end());
			r.pop_back();
			q.push(r);
		}
	}
	cout << ans << endl;
	return 0;
}
