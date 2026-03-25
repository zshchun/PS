#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<ll,ll> pi;
typedef pair<ll,string> ps;
#define endl "\n"
#define INF 123456789
vector<string> ans;
ll s, t;

void bfs() {
	queue<ps> q;
	q.push(ps(s, ""));
	q.push(ps(1, "/"));
	while (!q.empty()) {
		auto [cur, st] = q.front();
		q.pop();
		if (ans.size() > 0 && st.size() > ans[0].size())
			break;
		if (cur == t) {
			ans.push_back(st);
			continue;
		}
		if (cur > 1 && cur * cur <= t)
			q.push(ps(cur*cur, st+"*"));
		if (cur + cur <= t)
			q.push(ps(cur+cur, st+"+"));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j;
	cin >> s >> t;
	if (s == t) {
		cout << "0\n";
		return 0;
	}
	bfs();
	sort(ans.begin(), ans.end(), [&](const string lhs, const string rhs) {
		if (lhs.size() == rhs.size())
			return lhs < rhs;
		return lhs.size() < rhs.size();
	});
	if (ans.size() > 0)
		cout << ans[0] << endl;
	else
		cout << "-1\n";
	return 0;
}
