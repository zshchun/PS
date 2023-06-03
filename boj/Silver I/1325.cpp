#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
ll n, m, cnt, ans;
vector<ll> g[10001];
ll visited[10001];

void dfs(ll x) {
	if (visited[x])
		return;
	visited[x] = 1;
	cnt++;

	for (ll y : g[x]) {
		dfs(y);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, u, v, idx;
	vector<ll> a;

	cin >> n >> m;
	for (i=0;i<m;i++) {
		cin >> v >> u;
		g[u].push_back(v);
	}
	for (i=1;i<=n;i++) {
		cnt = 0;
		fill(visited, visited+n+1, 0);
		dfs(i);
		if (cnt > ans) {
			ans = cnt;
			a.clear();
			a.push_back(i);
		} else if (cnt == ans) {
			a.push_back(i);
		}
	}
	sort(a.begin(), a.end());
	for (ll x : a) {
		cout << x << ' ';
	}
	cout << endl;

	return 0;
}
